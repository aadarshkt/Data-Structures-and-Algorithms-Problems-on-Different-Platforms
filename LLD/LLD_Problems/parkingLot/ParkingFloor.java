package parkingLot;

import lombok.AllArgsConstructor;
import lombok.Data;

import java.util.List;

@Data
@AllArgsConstructor
public class ParkingFloor {
    private int floorNumber;
    private List<ParkingSpot> parkingSpots;
}
