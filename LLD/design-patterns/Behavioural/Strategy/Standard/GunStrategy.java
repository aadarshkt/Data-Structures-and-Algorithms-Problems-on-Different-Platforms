package Behavioural.Strategy.Standard;

public class GunStrategy implements Strategy{
    @Override
    public void execute() {
    System.out.println("I will use a gun");
    }
}
