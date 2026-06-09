package parkingLot;

public class CreditCardPaymentStrategy implements PaymentStrategy{
    @Override
    public void pay(int amount) {
        System.out.println("Paying through credit card " + amount);
    }
}
