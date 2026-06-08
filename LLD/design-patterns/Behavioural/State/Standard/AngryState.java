package Behavioural.State.Standard;

import lombok.extern.slf4j.Slf4j;


@Slf4j
public class AngryState implements State{

    private final Mammoth mammoth;

    public AngryState(Mammoth mammoth) {
        this.mammoth = mammoth;
    }

    @Override
    public void observe() {
        log.info("{} mammoth is in angry state", mammoth);
    }

    @Override
    public void onEnterState() {
        log.info("{} is entering angry state", mammoth);
    }
}
