package TicketBooking;

import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;

@Data
 class Concert {
    private String concertID;
    private String concertName;
    private List<Artist> artists;
    private Set<Seat> seats = ConcurrentHashMap.newKeySet();
    private String venue;
    private LocalDateTime eventTime;
    private Queue<Booking> bookingQueue;

    void addArtist(Artist artist) {
        artists.add(artist);
    }

    void removeArtist(Artist artist) {
        if(artists.contains(artist)) {
            artists.remove(artist);
        } else {
            System.out.println("This concert doesn't have this artist");
        }
    }

    void addToBookingQueue(Booking booking) {
        bookingQueue.add(booking);
    }

    Booking popFromBookingQueue() {
        return bookingQueue.poll();
    }
}
