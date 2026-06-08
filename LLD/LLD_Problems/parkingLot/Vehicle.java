package parkingLot;

import lombok.AllArgsConstructor;

@AllArgsConstructor
public abstract class Vehicle {
    String licensePlate;
    Member member;
    VehicleType vehicleType;
}
