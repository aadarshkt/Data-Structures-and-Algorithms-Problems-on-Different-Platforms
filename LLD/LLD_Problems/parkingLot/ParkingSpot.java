package parkingLot;

import lombok.AllArgsConstructor;
import lombok.Data;

import java.util.concurrent.atomic.AtomicBoolean;

@Data
@AllArgsConstructor
public class ParkingSpot {
    String spotId;
    ParkingSpotType parkingSpotType;
    AtomicBoolean isEmpty = new AtomicBoolean(true);

    public boolean tryReserve() {
        return isEmpty.compareAndSet(true, false);
    }

    public boolean tryRelease() {
        return isEmpty.compareAndSet(false, true);
    }
}
