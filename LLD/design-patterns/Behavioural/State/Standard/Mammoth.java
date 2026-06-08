package Behavioural.State.Standard;

public class Mammoth {
    private State state;

    public Mammoth() {
        this.state = new PeacefulState(this);
    }

    public void changeState() {
        if(state.getClass().equals(PeacefulState.class)) {
            changeStateTo(new AngryState(this));
        } else {
            changeStateTo(new PeacefulState(this));
        }
    }

    private void changeStateTo(State state) {
        this.state = state;
        this.state.onEnterState();
    }

    public void observe() {
        this.state.observe();
    }

}
