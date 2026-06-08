package Behavioural.Strategy.Problem;

import java.util.Objects;

public class PaymentService {

    //Violates Open/Close principle.
    public void processPayment(String paymentMethod) {
        if(Objects.equals(paymentMethod, "Credit Card")) {
            System.out.println("Logic for credit card payment.");
        } else if(paymentMethod.equals("Debit card")) {
            System.out.println("Logic for debit card payment.");
        } else {
            System.out.println("PaymentService method not supported.");
        }
    }
}
