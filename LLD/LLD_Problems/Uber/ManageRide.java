package Uber;

public class ManageRide {
    static void manageRide(Ride ride) {
        ride.addObserver(ride.getRider());
        ride.addObserver(ride.getDriver());

        ride.getRider().notify("Driver: " + ride.getDriver().name + " is coming to pick you up");

        //Update the status of observers
        ride.changeRideStatus(RideStatus.ASSIGNED);

        //Notify the driver
        ride.getDriver().notify("You have to reach location " + ride.getRider().currentLocation);

        //Pickup
        ride.changeRideStatus(RideStatus.ONGOING);

        //completed
        ride.changeRideStatus(RideStatus.COMPLETED);
    }
}
