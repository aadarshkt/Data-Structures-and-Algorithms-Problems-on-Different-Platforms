package Structural.decorator.solution2;

public class SimplePizza implements Pizza{
    @Override
    public String getDescription() {
        return "A simple pizza";
    }

    @Override
    public int getCost() {
        return 10;
    }
}
