package Structural.decorator.problem;

public class SimplePizza implements Pizza{
    @Override
    public String getDescription() {
        return "Simple Pizza";
    }

    @Override
    public int getCost() {
        return 10;
    }
}
