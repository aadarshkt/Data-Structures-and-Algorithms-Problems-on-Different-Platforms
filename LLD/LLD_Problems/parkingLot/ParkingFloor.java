package parkingLot;

import lombok.AllArgsConstructor;
import lombok.Data;

import java.util.List;

@Data
@AllArgsConstructor
public class ParkingFloor {
    int floorNumber;
    List<ParkingSpot> parkingSpots;
}
