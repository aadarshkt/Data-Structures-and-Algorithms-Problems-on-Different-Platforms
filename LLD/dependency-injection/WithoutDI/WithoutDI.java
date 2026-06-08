package WithoutDI;

public class WithoutDI {
    public static void main(String[] args){
        NotificationService notificationService = new NotificationService();

        //tightly coupled with email service.

        //In order to add more methods of sending you need to edit to the notification service.

        notificationService.sendNotification();
    }
}
