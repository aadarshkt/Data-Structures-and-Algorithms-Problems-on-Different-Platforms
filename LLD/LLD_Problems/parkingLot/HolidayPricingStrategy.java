package parkingLot;

import java.time.Duration;

public class HolidayPricingStrategy implements PricingStrategy{
    @Override
    public int getPrice(ParkingTicket ticket) {
        long totalTime = Math.max(1, Duration.between(ticket.getEntryTime(), ticket.getExitTime()).toHours());
        ParkingSpotType parkingSpotType = ticket.getParkingSpot().getParkingSpotType();

        int rate = parkingSpotType.getHourlyRate();
        return (int)(rate * totalTime * 0.5);
    }
}
