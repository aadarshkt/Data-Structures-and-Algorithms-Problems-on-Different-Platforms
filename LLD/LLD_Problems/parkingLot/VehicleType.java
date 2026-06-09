package parkingLot;

import lombok.Getter;

@Getter
public enum VehicleType {
    TWO_WHEELER(ParkingSpotType.TWO_WHEELER),
    FOUR_WHEELER(ParkingSpotType.FOUR_WHEELER),
    EV_TWO_WHEELER(ParkingSpotType.EV_TWO_WHEELER),
    EV_FOUR_WHEELER(ParkingSpotType.EV_FOUR_WHEELER),
    EXTRA_LARGE(ParkingSpotType.EXTRA_LARGE);

    private final ParkingSpotType requiredSpotType;

    VehicleType(ParkingSpotType requiredSpotType) {
        this.requiredSpotType = requiredSpotType;
    }
}
