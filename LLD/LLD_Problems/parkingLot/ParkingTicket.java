package parkingLot;

import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
public class ParkingTicket {
    private String ticketId;
    private Vehicle vehicle;
    private long entryTime;
    private long exitTime;
    private ParkingSpot parkingSpot;
}
