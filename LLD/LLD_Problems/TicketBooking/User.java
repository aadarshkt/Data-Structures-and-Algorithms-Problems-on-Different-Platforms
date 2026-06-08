package TicketBooking;

import lombok.Data;

import java.util.List;

@Data
class User {
    private String userID;
    private String username;
    private String email;
    private PaymentMethod paymentMethod;
    private List<Notification> notifications; //notification method user has opted for.

    void notify(String updates) {
        System.out.println(updates);
    }

    void refund(double amount) {
        System.out.println("You have been refunded " + amount + " RS");
    }

    void sendNotifications(Booking booking) {
        if (notifications != null) {
            notifications.forEach(notification -> notification.sendNotification(booking));
        }
    }
}
