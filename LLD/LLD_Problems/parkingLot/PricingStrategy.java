package parkingLot;

public interface PricingStrategy {
    int getPrice(ParkingTicket ticket);
}
