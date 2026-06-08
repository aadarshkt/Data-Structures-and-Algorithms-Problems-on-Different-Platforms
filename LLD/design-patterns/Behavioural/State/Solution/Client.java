package Behavioural.State.Solution;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class Client {
    public static void main(String[] args){
        DirectionService directionService = new DirectionService();

        directionService.setTransportMode(new Bike());
        log.info(String.valueOf(directionService.getETA()));
        log.info(directionService.getDirections());

        directionService.setTransportMode(new Car());

        log.info(String.valueOf(directionService.getETA()));
        log.info(directionService.getDirections());
    }
}
