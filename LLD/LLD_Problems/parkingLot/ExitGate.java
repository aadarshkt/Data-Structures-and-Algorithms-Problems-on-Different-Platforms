package parkingLot;

import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@AllArgsConstructor
@NoArgsConstructor
public class ExitGate extends Gate{
    @Override
    public void openBarrier() {
        System.out.println("Exit gate opening");
    }

    @Override
    public void closeBarrier() {
        System.out.println("Exit gate closing");
    }
}
