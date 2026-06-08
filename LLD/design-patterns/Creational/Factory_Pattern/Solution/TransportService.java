package Creational.Factory_Pattern.Solution;

public class TransportService {
    public static void main(String[] args) {
        //Use factory
        Transport vehicle = TransportFactory.createTransport("car");
        Transport vehicle2 = TransportFactory.createTransport("bus");

        vehicle.deliver();
        vehicle2.deliver();

        //Benefits
        //1. If the object creation logic is very complex, you can delegate it to another class.
        //Deligation is  the first benefit.
        //2. The code becomes much more dynamic and can change at runtime, for eg, you want to
        //take user input and then create a car, although that can be done through a simple method.
        //3. Tomorrow if implementation of car changes, you don't need to modify the client's code.
        //4. Thus, it is closed for modification upon car class editing.
        //5. This is open of extension.
        //6. Also demonstrates Single Responsibility principle, Transport Service need not handle
        //an Object creation process.
    }
}
