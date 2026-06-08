package Uber;

import java.time.Duration;

import static Uber.Helper.calcDistance;

public class Luxury implements FeeStrategy{
    @Override
    public double calculate(Location pickupLocation, Location dropoffLocation, Vehicle vehicle, Duration duration) {
        double distance = calcDistance(pickupLocation, dropoffLocation);

    return distance
        * vehicle.getFarePerKM()
        * 2
        * duration.getSeconds()
        * vehicle.getFarePerSecond();
    }
}
