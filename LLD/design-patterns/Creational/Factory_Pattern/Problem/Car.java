package Creational.Factory_Pattern.Problem;

public class Car implements Transport {
    @Override
    public void deliver() {
        System.out.println("Delivery through car");
    }
}
