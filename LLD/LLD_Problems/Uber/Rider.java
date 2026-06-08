package Uber;

import lombok.Data;
import lombok.EqualsAndHashCode;

@Data
@EqualsAndHashCode(callSuper = true)
public class Rider extends User implements Observer {

    String riderID;
    PaymentStrategy paymentStrategy;
    Location destination;

    public Rider(String name, String riderID, Location currentLocation, Location destination,  PaymentStrategy paymentStrategy) {
        super(name, currentLocation);
        this.riderID = riderID;
        this.paymentStrategy = paymentStrategy;
        this.destination = destination;
    }

    @Override
    public void observe(RideStatus rideStatus) {
    System.out.println("Rider ride status is " + rideStatus.toString());
  }

    @Override
    public void notify(String notification) {
    System.out.println("Rider: You have a new notification " + notification);
    }
}
