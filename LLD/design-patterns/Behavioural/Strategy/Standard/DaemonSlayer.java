package Behavioural.Strategy.Standard;

import lombok.Setter;

@Setter
public class DaemonSlayer {
    private Strategy strategy;

    public void goToBattle() {
        strategy.execute();
    }
}
