package Behavioural.Strategy.Solution;

import lombok.Setter;

@Setter
public class PaymentService {
    private PaymentStrategy paymentStrategy;

    public void pay() {
        paymentStrategy.processPayment();
    }
}
