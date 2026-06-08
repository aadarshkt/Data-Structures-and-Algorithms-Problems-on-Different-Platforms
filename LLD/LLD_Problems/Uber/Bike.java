package Uber;

public class Bike extends Vehicle{
    public Bike(String licenseNumber) {
        super(licenseNumber);
    }

    @Override
    double getFarePerKM() {
        return 10;
    }

    @Override
    double getFarePerSecond() {
        return 0.001;
    }
}
