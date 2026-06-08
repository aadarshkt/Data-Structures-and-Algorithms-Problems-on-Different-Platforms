package TicketBooking;

 class EmailNotification extends Notification{
    @Override
    void sendNotification(Booking booking) {
        booking.getUser().notify("Hi, your booking is confirmed" + booking.getBookingID());
    }
}
