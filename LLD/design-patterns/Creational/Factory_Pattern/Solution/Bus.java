package Creational.Factory_Pattern.Solution;

public class Bus implements Transport{
    @Override
    public void deliver() {
        System.out.println("Deliver by bus");
    }
}
