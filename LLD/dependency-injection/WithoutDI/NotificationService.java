package WithoutDI;

public class NotificationService {

    private final EmailSender emailSender;

    public NotificationService() {
        this.emailSender = new EmailSender();
    }

    public void sendNotification(){
        emailSender.send();
    }
}
