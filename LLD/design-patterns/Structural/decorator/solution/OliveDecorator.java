package Structural.decorator.solution;

//Decorator class
public class OliveDecorator implements Pizza{

    private final Pizza pizza;

    public OliveDecorator(Pizza pizza) {
        this.pizza = pizza;
    }

    @Override
    public String getDescription() {
    return pizza.getDescription() +  " and olives";
    }

    @Override
    public int getCost() {
        return pizza.getCost() + 5;
    }
}
