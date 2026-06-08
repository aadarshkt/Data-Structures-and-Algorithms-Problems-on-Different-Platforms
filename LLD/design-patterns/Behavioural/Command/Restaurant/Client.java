package Behavioural.Command.Restaurant;

public class Client {
    public static void main(String[] args){

        //Creating the request object.
        MakeBurgerCommand makeBurgerCommand = new MakeBurgerCommand();
        Chef chef = new Chef();
        makeBurgerCommand.setChef(chef);

        Waiter waiter = new Waiter();

        waiter.takeOrder(makeBurgerCommand);
        waiter.placeOrder(makeBurgerCommand);

        MakePizzaCommand makePizzaCommand = new MakePizzaCommand();
        makePizzaCommand.setChef(chef);

        waiter.takeOrder(makePizzaCommand);
        waiter.placeOrder(makePizzaCommand);
    }
}
