package Creational.Prototype;

import lombok.Getter;

@Getter
public class Shape implements Prototype<Shape>{
    private final int area;
    private final String type;
    private final String perimeter;

    public Shape(int area, String type, String perimeter) {
        this.area = area;
        this.type = type;
        this.perimeter = perimeter;
    }

    @Override
    public Shape clone() {
        return new Shape(this.area, this.type, this.perimeter);
    }
}
