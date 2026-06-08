package Behavioural.Command.Restaurant;


//Invoker
public class Waiter {
    private Command command;

    void takeOrder(Command order) {
        this.command = order;
    }

    void placeOrder(Command order) {
        this.command.execute();
    }
}
