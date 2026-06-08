package Guice;

public class SMSService implements MessageService {
    @Override
    public void sendMessage(String recipient, String message) {
        System.out.println("SMS sent to " + recipient + ": " + message);
    }
}
