package Behavioural.Mediator.Solution;

public class User2 extends User{

    User2(Mediator mediator, String name) {
        super(mediator, name);
    }


    @Override
    void send(String message) {
        mediator.sendMessage(message, this);
    }

    @Override
    void receive(String message) {
        //Which user has sent a message is configurable.
        System.out.println(this.name + " Received The message from a user is" + " " + message);
    }
}

