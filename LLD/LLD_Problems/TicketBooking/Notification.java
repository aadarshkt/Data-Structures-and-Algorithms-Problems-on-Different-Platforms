package TicketBooking;

abstract class Notification {
    private String notificationID;

    abstract void sendNotification(Booking booking);
}
