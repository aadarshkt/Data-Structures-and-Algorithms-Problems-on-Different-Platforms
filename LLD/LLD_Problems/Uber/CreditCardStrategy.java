package Uber;

public class CreditCardStrategy implements PaymentStrategy{
    @Override
    public void pay(double amount) {
    System.out.println("Paying via credit card for amount " + amount);
    }
}
