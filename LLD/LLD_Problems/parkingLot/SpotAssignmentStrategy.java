package parkingLot;

import java.util.List;

public interface SpotAssignmentStrategy {
    ParkingSpot getParkingSpot(Vehicle vehicle, List<ParkingFloor> parkingFloors, Gate gate);
}
