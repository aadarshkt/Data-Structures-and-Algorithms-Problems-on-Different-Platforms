package TicketBooking;

import lombok.Data;

@Data
 class Booking {
    String BookingID;
    Concert concert;
    User user;
    Seat seat;
    BookingStatus bookingStatus;

    Booking(String bookingID, Concert concert, User user, Seat seat, BookingStatus bookingStatus) {
        BookingID = bookingID;
        this.concert = concert;
        this.user = user;
        this.seat = seat;
        this.bookingStatus = bookingStatus;
    }

    void confirmBooking() {
        this.bookingStatus = BookingStatus.CONFIRMED;
    }

    void cancelBooking() {
        this.bookingStatus = BookingStatus.CANCELLED;
    }
}
