package Behavioural.Memento.Standard;

import java.util.Stack;

public class CareTaker {
    public static void main(String[] args){
        var states = new Stack<StarMemento>();

        var star = new Star(StarType.SUN, 10000000, 500000);

        System.out.println(star.toString());
        states.add(star.getMemento());
        star.timePasses();
        System.out.println(star.toString());
        states.add(star.getMemento());
        star.timePasses();
        System.out.println(star.toString());
        states.add(star.getMemento());
        star.timePasses();
        System.out.println(star.toString());
        states.add(star.getMemento());
        star.timePasses();
        System.out.println(star.toString());

        while (!states.isEmpty()) {
            //Request to restore state.
            star.setMemento(states.pop());
            System.out.println(star.toString());
        }
    }
}
