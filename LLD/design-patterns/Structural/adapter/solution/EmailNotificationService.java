package Structural.adapter.solution;

//Concreate internal class already used at many places in the code.
public class EmailNotificationService implements EmailService {
    @Override
    public void send(String username, String domainName, String content) {
    System.out.println("Send email to " + username + "@"
            + domainName + " with this content " + content);
    }
}
