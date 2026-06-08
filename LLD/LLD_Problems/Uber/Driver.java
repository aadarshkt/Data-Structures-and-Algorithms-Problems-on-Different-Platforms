package Uber;

import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.concurrent.atomic.AtomicReference;

@Data
@EqualsAndHashCode(callSuper = true)
public class Driver extends User implements Observer {
    private String driverID;
    private Vehicle currentVehicle;
    private AtomicReference<DriverStatus> driverStatus = new AtomicReference<>(DriverStatus.AVAILABLE);

    Driver(String name, Location currentLocation, Vehicle currentVehicle) {
        super(name, currentLocation);
        this.currentVehicle = currentVehicle;
    }

    public boolean tryAssignDriver() {
        return this.driverStatus.compareAndSet(DriverStatus.AVAILABLE, DriverStatus.ASSIGNED);
    }

    @Override
    public void observe(RideStatus rideStatus) {
    System.out.println("Driver's ride status has updated to " + rideStatus.toString());
    }

    @Override
    public void notify(String notification) {
    System.out.println("Driver: You have a notification " + notification);
    }
}
