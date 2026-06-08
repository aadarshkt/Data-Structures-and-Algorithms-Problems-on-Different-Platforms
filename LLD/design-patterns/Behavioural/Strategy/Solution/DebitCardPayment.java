package Behavioural.Strategy.Solution;

public class DebitCardPayment implements PaymentStrategy{
    @Override
    public void processPayment() {
        System.out.println("Logic for debit card payment");
    }
}
