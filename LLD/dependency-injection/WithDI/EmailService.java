package WithDI;

public class EmailService implements IMessageSender{
    @Override
    public void send(String message) {
        System.out.println("The message from email service is " + message);
    }
}
