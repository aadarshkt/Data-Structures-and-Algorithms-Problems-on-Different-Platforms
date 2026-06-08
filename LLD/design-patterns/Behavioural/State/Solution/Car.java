package Behavioural.State.Solution;

public class Car implements TransportMode{
    @Override
    public int calculateETA() {
        return 10;
    }

    @Override
    public String getDirections() {
        return "Left Right Left";
    }
}
