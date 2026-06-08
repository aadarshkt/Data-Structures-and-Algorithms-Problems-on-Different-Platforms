//package Guice;
//
//import com.google.inject.Guice;
//import com.google.inject.Injector;
//
//public class Main {
//    public static void main(String[] args) {
//        Injector injector = Guice.createInjector(new NotificationModule());
//        NotificationService notificationService = injector.getInstance(NotificationService.class);
//
//        notificationService.sendNotification("john.doe@example.com", "Your order has been shipped!");
//
//    }
//}
