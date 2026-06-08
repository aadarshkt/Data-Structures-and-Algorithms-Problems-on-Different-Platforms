package Uber;

public interface Observer {
    void observe(RideStatus rideStatus);
    void notify(String notification);
}
