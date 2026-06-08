package Behavioural.Mediator.Solution;

import java.util.ArrayList;
import java.util.List;

public class ConcreteMediator implements Mediator{

    private final List<User> users = new ArrayList<User>();

    @Override
    public void sendMessage(String message, User sender) {
        //Can be configured to send a message to just on receiver.
        for(User user : users) {
            if(user != sender) {
                user.receive(message);
            }
        }
    }

    @Override
    public void addUser(User user) {
        users.add(user);
    }
}
