package Structural.facade.solution;

import Structural.facade.problem.UserService;

public class APIGateway {
    UserService userService;
    OrderService orderService;
    PaymentService paymentService;

    public APIGateway() {
        this.userService = new UserService();
        this.orderService = new OrderService();
        this.paymentService = new PaymentService();
    }

    public String processOrder(String userId, String orderId, String paymentId) {
        userService.setUserId(userId);
        orderService.setOrderId(orderId);
        paymentService.setPaymentId(paymentId);

        return "Order processed for user: " + userService.getUserId() +
                           " with order ID: " + orderService.getOrderId() +
                           " and payment ID: " + paymentId;
    }
}
