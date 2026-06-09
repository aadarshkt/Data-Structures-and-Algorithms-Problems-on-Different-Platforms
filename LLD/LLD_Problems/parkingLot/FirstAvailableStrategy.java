package parkingLot;

import java.util.List;

public class FirstAvailableStrategy implements SpotAssignmentStrategy {
    @Override
    public ParkingSpot getParkingSpot(Vehicle vehicle, List<ParkingFloor> parkingFloors, Gate gate) {
        for(ParkingFloor parkingFloor : parkingFloors) {
            for(ParkingSpot spot: parkingFloor.getParkingSpots()) {
                if(vehicle.getVehicleType().getRequiredSpotType() == spot.getParkingSpotType() && spot.getIsEmpty().get()) {
                    if(spot.tryReserve()) {
                        return spot;
                    }
                }
            }
        }
        
        // If we exhausted all spots on all floors, return null to indicate the lot is full for this vehicle type
        return null;
    }
}
