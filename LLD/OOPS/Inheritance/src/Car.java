public class Car extends Vehicle {
    int numWheels;
    Car(double speed, double fuel, int numWheels){
        super(speed, fuel);
        this.numWheels = numWheels;
    }
    void goBackward(){
        System.out.println("The vehicle is going backward");
    }

    void airConditioning(){
        System.out.println("Air conditioning implementation");
    }

}
