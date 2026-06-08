package Behavioural.Memento.Standard;

import lombok.Getter;
import lombok.Setter;

//Originator //Whose state will be stored.
public class Star {
    private StarType type;
    private int age;
    private int mass;

    public Star(StarType type, int age, int mass) {
        this.type = type;
        this.age = age;
        this.mass = mass;
    }

    public void timePasses() {
        age *= 2;
        mass *= 8;
        switch (type) {
            case RED_GIANT -> type = StarType.WHITE_DWARF;
            case SUN -> type = StarType.RED_GIANT;
            case SUPERNOVA -> type = StarType.DEAD;
            case WHITE_DWARF -> type = StarType.SUPERNOVA;
            case DEAD -> {
                age *= 2;
                mass = 0;
            }
            default -> {
            }
        }
    }

    StarMemento getMemento() {
        var state = new StarInternalMemento();
        state.setAge(this.age);
        state.setMass(this.mass);
        state.setType(this.type);
        return state;
    }

    void setMemento(StarMemento memento) {
        var state = (StarInternalMemento) memento;
        this.type = state.getType();
        this.age = state.getAge();
        this.mass = state.getMass();
    }

    @Override
    public String toString() {
        return "Star{" +
                "type=" + type +
                ", age=" + age +
                ", mass=" + mass +
                '}';
    }

    //Class for storing internal state;
    @Getter
    @Setter
    public static class StarInternalMemento implements StarMemento {
        private StarType type;
        private int age;
        private int mass;
    }
}
