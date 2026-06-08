package TicketBooking;

import lombok.Data;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.UUID;
import java.util.concurrent.*;

@Data
class BookingManager {
    private final Map<String, Concert> concerts;
    private final Map<String, Booking> bookings;

    // Scheduler for releasing seats after 10-min payment window
    private final ScheduledExecutorService scheduler = Executors.newScheduledThreadPool(2);
    // Tracks in-flight timers so we can cancel them when payment arrives in time
    private final Map<String, ScheduledFuture<?>> pendingTimers = new ConcurrentHashMap<>();


    /**Singleton pattern implementation
     * 1. constructor should be private because only internal method should be able to create instance.
     * 2. Create one STATIC variable to store the instance. initialize it as null
     * 3. apply double-checked locking (null check + synchronized + null check again) for thread safety.
     * 4. If not null return the previous instance.
     */

    // static: shared across all (non-existent) instances; volatile: ensures visibility across threads
    private static volatile BookingManager bookingManagerInstance = null;

    private BookingManager() {
        this.concerts = new HashMap<>();
        this.bookings = new HashMap<>();
    }

    // static: callable without an existing instance; synchronized block for thread safety
     static BookingManager getBookingManagerInstance() {
        if (bookingManagerInstance == null) {                      // first check (no lock)
            synchronized (BookingManager.class) {
                if (bookingManagerInstance == null) {              // second check (with lock)
                    bookingManagerInstance = new BookingManager();
                }
            }
        }
        return bookingManagerInstance;
    }

     void addConcert(Concert concert) {
        this.concerts.put(concert.getConcertID(), concert);
    }

     Concert getConcert(String concertID) {
        return concerts.get(concertID);
    }

     Booking getBooking(String bookingID) {
        return bookings.get(bookingID);
    }

    List<Seat> getEmptySeats(Concert concert) {
        List<Seat> emptySeats = new ArrayList<>();
        for (Seat seat : concert.getSeats()) {
            if (seat.getSeatStatus() == SeatStatus.AVAILABLE) emptySeats.add(seat);
        }
        return emptySeats;
    }

    List<Concert> getAllConcerts() {
        return new ArrayList<>(this.concerts.values());
    }

    Booking book(User user, Concert concert, Seat userSeat) {
        for (Seat seat : concert.getSeats()) {
            if (seat.getSeatID().equals(userSeat.getSeatID())) {
                // tryPend() is a single atomic CAS instruction — no lock needed.
                // Only the ONE thread that flips AVAILABLE→PENDING proceeds; all others get false.
                if (seat.tryPend()) {
                    String bookingID = UUID.randomUUID().toString();
                    Booking newBooking = new Booking(bookingID, concert, user, seat, BookingStatus.PENDING);
                    bookings.put(newBooking.getBookingID(), newBooking);

                    // Schedule a 10-minute timeout: if payment hasn't arrived, release the seat.
                    ScheduledFuture<?> timer = scheduler.schedule(() -> {
                        // releasePending() is atomic: only succeeds if seat is still PENDING.
                        // If payment was already made (seat is BOOKED), this is a no-op.
                        if (seat.releasePending()) {
                            newBooking.cancelBooking();
                            pendingTimers.remove(newBooking.getBookingID());
                            // Give the released seat to the next waitlisted user, if any.
                            processWaitlist(seat, concert);
                        }
                    }, 10, TimeUnit.MINUTES);

                    pendingTimers.put(bookingID, timer);
                    return newBooking;
                }
                return null; // seat found but already PENDING or BOOKED
            }
        }
        return null; // seat not found in this concert
    }

    //Payment for single Booking
    boolean payForSeat(User user, Booking booking) throws BookingException {
        // Step 1 — Confirm the SEAT atomically: PENDING → BOOKED *before* charging.
        // If the 10-min timer already fired and released the seat back to AVAILABLE,
        // confirmSeat() returns false → bail out early with no payment attempted.
        if (!booking.getSeat(  ).confirmSeat()) {
            throw new BookingException("Payment window expired: seat was released before payment completed. Booking ID: " + booking.getBookingID());
        }

        // Step 2 — Seat is now BOOKED. Attempt payment.
        // If payment fails we must undo the seat confirmation so the seat doesn't stay locked forever.
        try {
            user.getPaymentMethod().pay(booking.getSeat().getSeatPrice());
        } catch (Exception e) {
            // Roll back: release the seat back to AVAILABLE so other users can book it.
            // SUGGESTION - we can implement retry for payment, if timer is available.
            booking.getSeat().cancelSeat();
            throw new BookingException("Payment failed: " + e.getMessage(), e);
        }

        // Step 3 — Cancel the pending release timer so it doesn't fire.
        ScheduledFuture<?> timer = pendingTimers.remove(booking.getBookingID());
        if (timer != null) {
            timer.cancel(false); // false = don't interrupt if already running (safe no-op if fired)
        }

        // Step 4 — Update the BOOKING status to CONFIRMED (separate from seat status).
        booking.confirmBooking();

        // Send notifications.
        user.sendNotifications(booking);

        return true;
    }

     boolean cancelBooking(Booking booking) throws BookingException {
        Seat seat = booking.getSeat();

        // cancelSeat()  handles BOOKED   → AVAILABLE (confirmed booking cancelled by user)
        // releasePending() handles PENDING → AVAILABLE (user cancels during the payment window)
        // Both are atomic CAS — only one path will succeed.
        boolean released = seat.cancelSeat() || seat.releasePending();
        if (!released) {
            throw new BookingException("Cannot cancel booking: seat is not in a cancellable state. Booking ID: " + booking.getBookingID());
        }

        // Cancel the auto-release timer if still in the payment window.
        ScheduledFuture<?> timer = pendingTimers.remove(booking.getBookingID());
        if (timer != null) {
            timer.cancel(false);
        }

        //cancel booking
        booking.cancelBooking();

        //refund user.
         booking.getUser().refund(booking.getSeat().getSeatPrice());

        //Trigger automatic popping and booking upon cancellation.
        processWaitlist(booking.getSeat(), booking.getConcert());

        return true;
    }

    //Fires when user chooses to go into waiting
     Booking addToQueue(User user, Concert concert) {
        String bookingID = UUID.randomUUID().toString();
        Booking newBooking = new Booking(bookingID, concert, user, null, BookingStatus.WAITLIST); //Current seat is null.
        concert.addToBookingQueue(newBooking);

        return newBooking;
    }

    //
    void payForWaitlistBooking(Booking booking) {
        try {
            booking.getUser().getPaymentMethod().pay(booking.getSeat().getSeatPrice());
        } catch (Exception e) {
          throw new RuntimeException(e);
        }
    }

    // User has already paid.
     Booking bookForQueueUser(Booking booking, Seat seat) throws BookingException {
        if (!seat.tryBook()) {
            throw new BookingException("Queue user cannot get booked seat");
        }

        //initially the booking had null seat, add seat.
        booking.setSeat(seat);

        booking.confirmBooking();
        booking.getUser().getNotifications().forEach(notification -> notification.sendNotification(booking));

        return booking;
  }

    /**
     * If the concert's waitlist queue is non-empty, pops the next pending booking,
     * assigns the freed seat to that user, and notifies them.
     * Called both from cancelBooking() and from the scheduler timeout in book().
     */
    private void processWaitlist(Seat canceledSeat, Concert concert) {
        if (concert.getBookingQueue().isEmpty()) return;

        Booking pendingBooking = concert.popFromBookingQueue();
        Booking confirmedBooking = null;

        try {
            confirmedBooking = bookForQueueUser(pendingBooking, canceledSeat);
        } catch (BookingException e) {
            pendingBooking.getUser().notify(
                    "Unfortunately, your waitlisted booking could not be completed — the seat was taken by another user. " +
                            "Please try booking again or join the waitlist for another seat."
            );
        }

        if (confirmedBooking != null) {
            confirmedBooking.getUser().notify("Your booking is confirmed after waitlist: " + confirmedBooking.getBookingID());
        }
    }

     List<Concert> search(LocalDateTime concertTime, String artistName, String venue) {
        List<Concert> searchResults = new ArrayList<Concert>();
        for (Concert concert : concerts.values()) {
            if (concert.getArtists().stream().anyMatch(artist -> artist.getName().equals(artistName))
                    && concert.getVenue().equals(venue)
                    && concert.getEventTime().equals(concertTime)) {
                searchResults.add(concert);
            }
        }

        return searchResults;
    }
}
