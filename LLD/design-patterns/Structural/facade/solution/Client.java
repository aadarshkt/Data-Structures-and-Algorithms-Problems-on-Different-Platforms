package Structural.facade.solution;

public class Client {
    public static void main(String[] args){
        APIGateway apiGateway = new APIGateway();
        System.out.println(apiGateway.processOrder("user123", "order456", "payment789"));
    }
}
