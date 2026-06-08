package Uber;

import java.time.Duration;

public interface FeeStrategy {
    double calculate(Location pickupLocation, Location dropoffLocation, Vehicle vehicle, Duration duration);
}
