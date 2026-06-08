package Behavioural.Strategy.Solution;

public class CreditCardPayment implements PaymentStrategy{
    @Override
    public void processPayment() {
    System.out.println("Logic for Credit card payment");
    }
}
