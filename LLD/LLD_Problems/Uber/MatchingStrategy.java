package Uber;

import java.util.List;

public interface MatchingStrategy {
    Driver match(List<Driver> currentActiveDrivers, Rider rider);
}
