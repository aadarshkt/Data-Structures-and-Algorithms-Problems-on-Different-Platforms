public class Vehicle {
    double speed;
    double fuel;

    Vehicle(double speed, double fuel){
        this.speed = speed;
        this.fuel = fuel;
    }

    void start(){
        System.out.println("The vehicle has started");
    }

    void stop(){
        System.out.println("The vehicle has stopped");
    }
}
