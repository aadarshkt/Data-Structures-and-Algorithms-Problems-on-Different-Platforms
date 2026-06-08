package Behavioural.State.Solution;

public class Bike implements TransportMode{
    @Override
    public int calculateETA() {
        return 5;
    }

    @Override
    public String getDirections() {
        return "Left Right Left";
    }
}
