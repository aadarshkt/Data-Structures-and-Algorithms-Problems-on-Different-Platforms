package Creational.Factory_Pattern.Problem;

public class TransportService {
    public static void main(String[] args) {
        Transport car = new Car();
        Transport bike = new Bike(); //Object creation tightly coupled to client service.
        //Violates open/close principle.
        //what if now Bike is called now motorBike, you need to update all the code
        //in the TransportService.
    }
}
