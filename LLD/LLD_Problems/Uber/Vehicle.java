package Uber;

abstract class Vehicle {
    String licenseNumber;

    Vehicle(String licenseNumber) {
        this.licenseNumber = licenseNumber;
    }

    abstract double getFarePerKM();

    abstract double getFarePerSecond();
}
