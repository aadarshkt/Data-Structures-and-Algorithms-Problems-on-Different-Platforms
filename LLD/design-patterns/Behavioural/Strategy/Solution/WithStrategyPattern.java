package Behavioural.Strategy.Solution;

public class WithStrategyPattern {
    public static void main(String[] args){
        PaymentService paymentService = new PaymentService();
    paymentService.setPaymentStrategy(new CreditCardPayment());

    paymentService.pay();

    paymentService.setPaymentStrategy(new DebitCardPayment());

    paymentService.pay();
    }
}
