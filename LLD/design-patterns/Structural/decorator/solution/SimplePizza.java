package Structural.decorator.solution;

public class SimplePizza implements Pizza{
    @Override
    public String getDescription() {
        return "This is a simple pizza";
    }

    @Override
    public int getCost() {
        return 10;
    }
}
