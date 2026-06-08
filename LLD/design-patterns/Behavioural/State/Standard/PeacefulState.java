package Behavioural.State.Standard;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class PeacefulState implements State{

    private final Mammoth mammoth;

    public PeacefulState(Mammoth mammoth) {
        this.mammoth = mammoth;
    }

    @Override
    public void observe() {
        log.info("{} is in peaceful state", mammoth);
    }

    @Override
    public void onEnterState() {
        log.info("{} is entering peaceful state", mammoth);
    }
}
