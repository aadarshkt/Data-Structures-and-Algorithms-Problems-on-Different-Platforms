package Behavioural.Mediator.Solution;

//Mediator
public interface Mediator {
    //Distribute message other than itself.
    void sendMessage(String message, User user);
    void addUser(User user);
}
