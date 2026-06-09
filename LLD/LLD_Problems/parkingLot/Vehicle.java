package parkingLot;

import lombok.AllArgsConstructor;
import lombok.Data;

@AllArgsConstructor
@Data
public abstract class Vehicle {
    private String licensePlate;
    private VehicleType vehicleType;
}
