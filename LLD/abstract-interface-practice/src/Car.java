public class Car extends Vehicle {
    public Car(String brand) {
        super(brand);
    }

    @Override
    void drive() {
        System.out.println("Implementation for car driving");
    }
}
