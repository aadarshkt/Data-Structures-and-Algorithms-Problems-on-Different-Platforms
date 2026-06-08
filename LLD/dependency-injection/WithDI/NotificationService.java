package WithDI;

public class NotificationService {
    private final IMessageSender messageSender;

    //Use DI here
    //@Inject
    //Same as saying I will not create my food, I will order it from a restaurant.
    //We can test it with multiple sender services.
    public NotificationService(IMessageSender messageSender) {
        this.messageSender = messageSender;
    }

    public void sendNotification(String message){
        messageSender.send(message);
    }
}
