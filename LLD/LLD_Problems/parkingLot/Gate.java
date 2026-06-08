package parkingLot;

public abstract class Gate {
    String gateId;
    DisplayBoard displayBoard;

    public abstract void openBarrier();
    public abstract void closeBarrier();
}
