package Guice;

public class EmailService implements MessageService {
    @Override
    public void sendMessage(String recipient, String message) {
        System.out.println("Email sent to " + recipient + ": " + message);
    }
}

