package parkingLot;

public class EntryGate extends Gate{
    @Override
    public void openBarrier() {
        System.out.println("Entry gate Opening");
    }

    @Override
    public void closeBarrier() {
        System.out.println("Entry gate closing");
    }
}
