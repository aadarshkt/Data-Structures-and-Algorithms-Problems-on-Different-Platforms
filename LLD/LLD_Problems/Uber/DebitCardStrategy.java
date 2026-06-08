package Uber;

public class DebitCardStrategy implements PaymentStrategy{
    @Override
    public void pay(double amount) {
    System.out.println("Paying via debit card on amount " + amount);
    }
}
