//package Guice;
//
//import com.google.inject.Inject;
//
//public class NotificationService {
//    private final MessageService messageService;
//
//    @Inject
//    public NotificationService(MessageService messageService) {
//        this.messageService = messageService;
//    }
//
//    public void sendNotification(String customer, String message) {
//        messageService.sendMessage(customer, message);
//    }
//}
