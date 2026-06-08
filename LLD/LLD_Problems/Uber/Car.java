package Uber;

public class Car extends Vehicle{

    public Car(String licenseNumber) {
        super(licenseNumber);
    }

    @Override
    double getFarePerKM() {
        return 30;
    }

    @Override
    double getFarePerSecond() {
        return 0.001;
    }
}
