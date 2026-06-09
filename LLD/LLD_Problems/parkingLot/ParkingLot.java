package parkingLot;

import java.util.List;

public class ParkingLot {
    // Singleton pattern instance
    private static ParkingLot instance = null;

    private List<ParkingFloor> parkingFloors;
    private List<Gate> gates; //Total gate list.
    
    // Strategies
    private SpotAssignmentStrategy spotAssignmentStrategy;
    private PricingStrategy pricingStrategy;

    // Private constructor for singleton
    private ParkingLot() {}

    public static synchronized ParkingLot getInstance() {
        if (instance == null) {
            instance = new ParkingLot();
        }
        return instance;
    }

    // Initialize the lot with data
    public void initialize(List<ParkingFloor> parkingFloors, List<Gate> gates, SpotAssignmentStrategy spotStrategy, PricingStrategy priceStrategy) {
        this.parkingFloors = parkingFloors;
        this.gates = gates;
        this.spotAssignmentStrategy = spotStrategy;
        this.pricingStrategy = priceStrategy;
    }

    // entry process
    public ParkingTicket processEntry(Vehicle vehicle, Gate entryGate) {
        // 1. Reserve spot using the strategy
        ParkingSpot spot = spotAssignmentStrategy.getParkingSpot(vehicle, this.parkingFloors, entryGate);

        if (spot == null) {
            throw new RuntimeException("Parking lot is completely full for vehicle type: " + vehicle.getVehicleType());
        }

        // 2. Generate parking ticket
        String ticketId = java.util.UUID.randomUUID().toString();
        long entryTime = System.currentTimeMillis();
        
        // Using constructor from lombok @AllArgsConstructor
        ParkingTicket ticket = new ParkingTicket(ticketId, vehicle, entryTime, 0L, spot);
        
        return ticket;
    }

    // exit process - Driver hands back ticket and chooses how to pay
    public void processExit(ParkingTicket ticket, Gate exitGate, PaymentStrategy paymentMethod) {
        // 1. Record exit time
        ticket.setExitTime(System.currentTimeMillis());
        
        // 2. Calculate the cost based on the current pricing rules of the parking lot
        int amountDue = pricingStrategy.getPrice(ticket);
        
        // 3. Process the payment using the method the driver selected
        paymentMethod.pay(amountDue);
        
        // 4. Finally, free up the parking spot so someone else can use it
        ticket.getParkingSpot().tryRelease();
    }
}
