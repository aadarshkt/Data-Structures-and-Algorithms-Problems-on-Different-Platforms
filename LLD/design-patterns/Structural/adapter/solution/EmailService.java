package Structural.adapter.solution;

//Internally used email service.
public interface EmailService {
    void send(String username, String domainName, String content);
}
