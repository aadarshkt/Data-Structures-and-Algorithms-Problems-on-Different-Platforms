package Structural.adapter.solution;

public class Client {
    public static void main(String[] args){
        EmailService emailNotificationService = new EmailNotificationService();
        emailNotificationService.send("aadarshkt1729", "gmail.com", "Your order is delivered");

        //Change one line
        EmailService sendGridAdapter = new SendGridAdapter(new SendGridService());
        sendGridAdapter.send("aadarshkt1729", "gmail.com", "Your order is delivered");

        //.send is all same.
    }
}
