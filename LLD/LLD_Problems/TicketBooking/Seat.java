package TicketBooking;

import lombok.Data;

import java.util.concurrent.atomic.AtomicReference;

@Data
 class Seat {
    private String seatID;
    private SeatType seatType;
    private final AtomicReference<SeatStatus> seatStatus = new AtomicReference<>(SeatStatus.AVAILABLE);
    private double seatPrice;



     Seat(String seatID, SeatType seatType, double seatPrice) {
        this.seatID = seatID;
        this.seatType = seatType;
        this.seatPrice = seatPrice;
    }

    /**
     * Atomically tries to book this seat.
     * Returns true only for the ONE thread that flips seatStatus AVAILABLE → BOOKED.
     * All other concurrent threads get false — no lock needed.
     */
     boolean tryBook() {
        return seatStatus.compareAndSet(SeatStatus.AVAILABLE, SeatStatus.BOOKED);
    }

    /**
     * Atomically tries to set this seat to PENDING (e.g., during payment window).
     * Returns true only for the ONE thread that flips seatStatus AVAILABLE → PENDING.
     */
     boolean tryPend() {
        return seatStatus.compareAndSet(SeatStatus.AVAILABLE, SeatStatus.PENDING);
    }

    /**
     * Confirms a PENDING seat as BOOKED (called when payment succeeds).
     * Returns true if the seat was successfully moved from PENDING → BOOKED.
     * Returns false if the timer already fired and released the seat back to AVAILABLE.
     */
     boolean confirmSeat() {
        return seatStatus.compareAndSet(SeatStatus.PENDING, SeatStatus.BOOKED);
    }

    /**
     * Releases a PENDING seat back to AVAILABLE (e.g., payment timeout).
     * Returns true if the seat was successfully moved from PENDING → AVAILABLE.
     */
     boolean releasePending() {
        return seatStatus.compareAndSet(SeatStatus.PENDING, SeatStatus.AVAILABLE);
    }

    /**
     * This method cancels the seat.
     */

     boolean cancelSeat() {
        return seatStatus.compareAndSet(SeatStatus.BOOKED, SeatStatus.AVAILABLE);
    }

     SeatStatus getSeatStatus() {
        return seatStatus.get();
    }
}
