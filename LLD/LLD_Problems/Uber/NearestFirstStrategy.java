package Uber;

import java.util.List;

import static Uber.Helper.calcDistance;

public class NearestFirstStrategy implements MatchingStrategy{
    @Override
    public Driver match(List<Driver> currentActiveDrivers, Rider rider) {
        double minDistance = Double.MAX_VALUE;
        Driver nearestDriver = null;
        for(Driver activeDriver : currentActiveDrivers) {
            double currDistance = calcDistance(rider.currentLocation, activeDriver.currentLocation);

            if(currDistance < minDistance) {
                minDistance = currDistance;
                nearestDriver = activeDriver;
            }
        }

        return nearestDriver;
    }
}
