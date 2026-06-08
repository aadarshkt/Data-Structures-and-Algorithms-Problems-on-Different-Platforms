package parkingLot;

import lombok.AllArgsConstructor;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@AllArgsConstructor
public class ParkingTicket {
    String ticketId;
    Vehicle vehicle;
    LocalDateTime entryTime;
    LocalDateTime exitTime;
    ParkingSpot parkingSpot;
}
