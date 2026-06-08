package Behavioural.Strategy.Standard;

public class KnifeStrategy implements Strategy{
    @Override
    public void execute() {
    System.out.println("I will use a knife");
    }
}
