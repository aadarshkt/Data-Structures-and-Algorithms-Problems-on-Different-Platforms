package Behavioural.Mediator.Solution;

public class User1 extends User{

    User1(Mediator mediator, String name) {
        super(mediator, name);
    }


    @Override
    void send(String message) {
        mediator.sendMessage(message, this);
    }

    @Override
    void receive(String message) {
        //Which user has sent a message is configurable.
        System.out.println(this.name + " received message, The message from a user is" + " " + message);
    }
}
