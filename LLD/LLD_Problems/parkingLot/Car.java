package parkingLot;

import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

public class Car extends Vehicle{
    public Car(String licensePlate, VehicleType vehicleType) {
        super(licensePlate, vehicleType);
    }
}
