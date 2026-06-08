package parkingLot;

import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
public class ParkingSpot {
    String spotId;
    ParkingSpotType parkingSpotType;
    boolean isEmpty;
}
