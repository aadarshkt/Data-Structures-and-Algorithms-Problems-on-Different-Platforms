package Behavioural.Mediator.Solution;


/**
 * 4 elements
 * 1. Mediator
 * 2. Colleague
 * 3. Concrete Mediator
 * 4. Concreate Mediator * Mediator -->
 * Mediator will contain data about all the colleagues and manage them.
 * It will pass a message from one to many or as required.
 * Colleague -->
 * Colleague will contain reference to mediator and will always send data to mediator
 * Colleague will contain method to send and receive messages.
 * Benefits
 * 1. THe main benefit of mediator is that mediator now has to take care to whom message will be sent.
 * 2. No tight coupling between colleagues.
 */
public class Client {
    public static void main(String[] args){
        Mediator mediator = new ConcreteMediator();
        User user1 = new User1(mediator, "Alison");
        User user2 = new User2(mediator, "Bob");

        //You can add user at the time of user creation as well,
        //better if configurable.
        mediator.addUser(user1);
        mediator.addUser(user2);

        user1.send("Hello everyone!");
    }
}
