package parkingLot;

public class NormalPricingStrategy implements PricingStrategy{
    @Override
    public int getPrice(ParkingTicket ticket) {
        long totalTime = Math.max(1, ticket.getExitTime() - ticket.getEntryTime());
        ParkingSpotType parkingSpotType = ticket.getParkingSpot().getParkingSpotType();

        int rate = parkingSpotType.getHourlyRate();
        return (int)(rate * totalTime);
    }
}
