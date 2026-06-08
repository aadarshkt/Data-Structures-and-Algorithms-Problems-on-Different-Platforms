package Behavioural.State.Problem;

import lombok.extern.slf4j.Slf4j;

//Violates open/close principle.
//Big class prone to errors.
//Hard to manage and extend.
@Slf4j
public class DirectionService {
    void getETA(TransportMode transportMode) {
        switch (transportMode){
            case CAR -> log.info("Logic for car ETA");
            case BUS -> log.info("Logic for bus ETA");
            case BIKE -> log.info("Logic for bike ETA");
            default -> log.info("Transport mode not found");
        }
    }

    void getDirection(TransportMode transportMode) {
        switch (transportMode) {
            case BUS -> log.info("Get directions for bus.");
            case CAR -> log.info("Get directions for car.");
            case BIKE -> log.info("Get directions for bike.");
            default -> log.error("Transport mode not found");
        }
    }
}
