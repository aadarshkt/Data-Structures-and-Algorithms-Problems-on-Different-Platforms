package Uber;

import lombok.Data;

import java.time.Duration;
import java.time.LocalDateTime;
import java.util.List;

@Data
public class Ride {
    private Rider rider;
    private Driver driver;
    private FeeStrategy feeStrategy;
    private Location pickupLocation;
    private Location dropoffLocation;
    private List<Observer> observerList;
    private LocalDateTime startTime;
    private LocalDateTime endTime;

    public Ride(Rider rider, Driver driver, FeeStrategy feeStrategy, Location pickupLocation,
            Location dropoffLocation) {
        this.rider = rider;
        this.driver = driver;
        this.feeStrategy = feeStrategy;
        this.pickupLocation = pickupLocation;
        this.dropoffLocation = dropoffLocation;
        this.startTime = LocalDateTime.now(); // Initialize with the current time
    }

    double calculateFee() {
        this.endTime = LocalDateTime.now();
        Duration rideDuration = Duration.between(startTime, endTime);
        return feeStrategy.calculate(pickupLocation, dropoffLocation, driver.getCurrentVehicle(), rideDuration);
    }

    void addObserver(Observer observer) {
        observerList.add(observer);
    }

    void removeObserver(Observer observer) {
        observerList.remove(observer);
    }

    void notifyObservers(RideStatus rideStatus) {
        for (Observer observer : observerList) {
            observer.observe(rideStatus);
        }
    }

    void changeRideStatus(RideStatus rideStatus) {
        notifyObservers(rideStatus);
    }
}
