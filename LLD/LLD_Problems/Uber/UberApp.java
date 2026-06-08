package Uber;

public class UberApp {
    public static void main(String[] args){
        MatchRiderDriver matchRiderDriver = new MatchRiderDriver(new NearestFirstStrategy());
        Location pickupLocation = new Location(33.33, 33.33);
        Location dropOffLocation = new Location(33.33, 33.34);
        Rider rider1 = new Rider("Ravi","abc123", pickupLocation, dropOffLocation, new CreditCardStrategy());


        Vehicle car1 = new Car("KA65LX4501");
        Vehicle bike1 = new Bike("KA45LX3450");
        Location location1 = new Location(33.33, 33.33); //same as pickup location
        //Two drivers one near one far.
        Driver driver1 = new Driver("Vijay", location1, car1);

        Location location2 = new Location(55.55, 55.55);
        Driver driver2 = new Driver("Arjun", location2, bike1);


        //register drivers
        matchRiderDriver.addActiveDriver(driver1);
        matchRiderDriver.addActiveDriver(driver2);

        //this automatically removes the one driver.
        Ride currRide = matchRiderDriver.requestRide(rider1, pickupLocation, dropOffLocation, new Luxury());

        ManageRide.manageRide(currRide);

        //Free the driver
        matchRiderDriver.addActiveDriver(currRide.getDriver());


        //Manage Payment.
        double totalFee = currRide.calculateFee();

        rider1.paymentStrategy.pay(totalFee);
    }
}
