package Uber;

import lombok.Data;

import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;


@Data
public class MatchRiderDriver {
  private final Set<Driver> currentActiveDrivers = ConcurrentHashMap.newKeySet(); //make individual operations atomic
    private MatchingStrategy matchingStrategy;

    public MatchRiderDriver(MatchingStrategy matchingStrategy) {
        this.matchingStrategy = matchingStrategy;
    }


    void addActiveDriver(Driver driver) {
        currentActiveDrivers.add(driver);
    }

    void removeActiveDriver(Driver driver) {
        currentActiveDrivers.remove(driver);
    }

    Ride requestRide(Rider rider, Location pickupLocation, Location dropoffLocation, FeeStrategy feeStrategy) {
        Driver matchedDriver = null;

        while (matchedDriver == null && !currentActiveDrivers.isEmpty()) {
            // select the nearest driver (simple fallback: pick the first active driver)
            Driver candidate = matchingStrategy.match(new ArrayList<>(currentActiveDrivers), rider);

            if(candidate == null) {
                rider.notify("No driver available for ride");
                return null;
            }

            if(candidate.tryAssignDriver()) {
                matchedDriver = candidate;
                currentActiveDrivers.remove(candidate);
            }
        }

        //create a new ride
        return new Ride(rider, matchedDriver, feeStrategy, pickupLocation, dropoffLocation);
    }
}
