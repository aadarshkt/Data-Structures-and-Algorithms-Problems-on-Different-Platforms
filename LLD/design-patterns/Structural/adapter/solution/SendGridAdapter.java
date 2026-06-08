package Structural.adapter.solution;

public class SendGridAdapter implements EmailService{

    SendGridService sendGridService;

    SendGridAdapter(SendGridService sendGridService) {
        this.sendGridService = sendGridService;
    }

    @Override
    public void send(String username, String domainName, String content) {
        //Map your service send method, which is used everywhere to sendgrid's
        //service
        sendGridService.send(username + "@" + domainName, content);
    }
}
