package Creational.Factory_Pattern.Problem;

public class Bike implements Transport{
    @Override
    public void deliver() {
        System.out.println("Delivery through bike");
    }
}
