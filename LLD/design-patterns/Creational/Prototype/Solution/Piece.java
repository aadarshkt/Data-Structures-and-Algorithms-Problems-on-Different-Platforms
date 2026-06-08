package Creational.Prototype.Solution;

import lombok.Getter;
import lombok.NonNull;
import lombok.Setter;

@Setter
@Getter
public class Piece extends Object implements Prototype<Piece> {
    @NonNull
    private String color;
    @NonNull
    private int position;

    public Piece(String color, int position) {
        this.color = color;
        this.position = position;
    }

    @Override
    public String toString() {
        return "Piece{" +
                "color='" + color + '\'' +
                ", position=" + position +
                '}';
    }

    //create a clone method that will return a deep copy of the current object in context.
    @Override
    public Piece clone() {
        return new Piece(this.color, this.position);
    }

}
