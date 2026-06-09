package parkingLot;

public class DebitCardPaymentStrategy implements PaymentStrategy{
    @Override
    public void pay(int amount) {
        System.out.println("Paying through debit card for amount " + amount);
    }
}
