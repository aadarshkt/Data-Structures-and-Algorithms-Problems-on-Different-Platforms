package parkingLot;


import lombok.Getter;

@Getter
public enum ParkingSpotType {
    TWO_WHEELER(10),
    FOUR_WHEELER(40),
    EV_TWO_WHEELER(15),
    EV_FOUR_WHEELER(45),
    EXTRA_LARGE(60);

    private final int hourlyRate;

    ParkingSpotType(int hourlyRate) {
        this.hourlyRate = hourlyRate;
    }
}
