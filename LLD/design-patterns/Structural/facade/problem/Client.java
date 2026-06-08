package Structural.facade.problem;

public class Client {
    public static void main(String[] args){
        UserService userService = new UserService();
        userService.setUserId("U123");

        OrderService orderService = new OrderService();
        orderService.setOrderId("O456");

        PaymentService paymentService = new PaymentService();
        paymentService.paymentId = "P789";

        // Client has to interact with all services directly
        System.out.println("Uber.User ID: " + userService.getUserId());
        System.out.println("Order ID: " + orderService.getOrderId());
        System.out.println("PaymentService ID: " + paymentService.paymentId);

        // Complex process to place an order
        // This complexity is exposed to the client
        // Additional logic to handle order placement would go here
        // ...
        // No common interface to simplify interactions
        // Client must manage interactions with multiple services
        // This leads to tight coupling and complexity
        // Therefore, use a facade pattern to simplify this in future
    }
}
