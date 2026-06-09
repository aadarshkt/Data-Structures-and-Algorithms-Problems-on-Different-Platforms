# Parking Lot LLD - Design Review

## 1. Architectural Overview
The current implementation successfully models a scalable, thread-safe Parking Lot system. It correctly identifies the core entities (`ParkingLot`, `ParkingFloor`, `ParkingSpot`, `Gate`, `Vehicle`) and establishes a clear hierarchy where the `ParkingLot` acts as the central orchestrator.

## 2. Key Strengths & Design Patterns
- **Concurrency Handling:** The use of `AtomicBoolean` inside `ParkingSpot` (`tryReserve()` and `tryRelease()`) is an elegant, non-blocking solution to the critical race condition problem. It avoids locking the entire `ParkingFloor`, which maximizes throughput for concurrent vehicles entering.
- **Strategy Pattern (Open/Closed Principle):**
  - **Spot Assignment:** The `SpotAssignmentStrategy` interface allows the system to easily swap between a `FirstAvailableStrategy` and future strategies (like `NearestToGateStrategy`) without modifying the `ParkingLot` core logic.
  - **Pricing & Payment:** Separating `PricingStrategy` (a business rule injected at startup) and `PaymentStrategy` (a user choice provided at exit) ensures the system can easily adapt to dynamic holiday pricing models or new payment gateways.
- **Singleton Pattern:** Ensuring `ParkingLot` is a singleton prevents chaotic state management across multiple entry gates.
- **Enum Mapping:** Linking `VehicleType` directly to its required `ParkingSpotType` cleans up conditional logic and makes the codebase highly readable.

## 3. End-to-End User Flow
### Entry Flow
1. A `Vehicle` arrives at an `EntryGate`.
2. The gate triggers `ParkingLot.getInstance().processEntry(vehicle, entryGate)`.
3. The `ParkingLot` delegates to the `SpotAssignmentStrategy`.
4. The strategy iterates through floors and spots. It matches the `VehicleType` to the required spot type and uses a thread-safe `tryReserve()` to lock a spot.
5. If successful, a `ParkingTicket` is generated with a unique ID, entry timestamp, and assigned spot, then returned to the user.

### Exit Flow
1. The driver arrives at an `ExitGate` and presents the `ParkingTicket` alongside a chosen `PaymentStrategy` (e.g., Credit Card).
2. The gate triggers `ParkingLot.getInstance().processExit(ticket, exitGate, paymentMethod)`.
3. The `ParkingLot` records the exit timestamp.
4. The fee is calculated using the injected `PricingStrategy`.
5. The payment is processed via the `PaymentStrategy`.
6. Finally, the `ParkingSpot` is instantly freed using `tryRelease()`.

## 4. Future Implementations & Interview Extensions
If asked how to scale or extend this system in an interview, here are the logical next steps to discuss:
- **Active Ticket Repository:** Currently, the system assumes the user hands back the exact `ParkingTicket` object. In a real system, the `ParkingLot` (or a database) should maintain a `Map<String, ParkingTicket>` to retrieve ticket details via Ticket ID or License Plate.
- **Display Boards (Observer Pattern):** Implementing an Observer pattern where the `DisplayBoard` at the entrance listens to `ParkingSpot` state changes to update the "Available Spots" count in real-time.
- **Distance/Coordinate Mapping:** To fully implement a `NearestToGateStrategy`, `ParkingSpot` and `Gate` entities would need physical coordinates (X, Y) to calculate proximity mathematically.
- **Graceful Downgrades:** Handling complex parking rules, like allowing a `CAR` to park in a `LARGE` spot if all `COMPACT` spots are full. This would involve upgrading the `FirstAvailableStrategy` to check fallback types if the primary type search fails.
