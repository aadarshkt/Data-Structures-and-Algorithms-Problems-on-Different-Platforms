package Behavioural.State.Solution;

import lombok.Setter;


//Context holds state.
@Setter
public class DirectionService {
    private TransportMode transportMode;

    public int getETA(){
        return transportMode.calculateETA();
    }

    public String getDirections() {
        return  transportMode.getDirections();
    }
}
