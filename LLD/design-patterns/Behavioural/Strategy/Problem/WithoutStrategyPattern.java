package Behavioural.Strategy.Problem;

public class WithoutStrategyPattern {
    public static void main(String[] args){
        PaymentService paymentService = new PaymentService();
        paymentService.processPayment("Credit Card");
    }
}
