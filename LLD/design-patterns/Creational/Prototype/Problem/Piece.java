package Creational.Prototype.Problem;

public class Piece {
    private String color;
    private int position;

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public int getPosition() {
        return position;
    }

    public void setPosition(int position) {
        this.position = position;
    }

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
}
