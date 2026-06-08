package Structural.decorator.solution;

//Decorator class.
public class CheezeDecorator implements Pizza{

    private final Pizza pizza;

    public CheezeDecorator(Pizza pizza) {
        this.pizza = pizza;
    }

    @Override
    public String getDescription() {
        return pizza.getDescription() + " and cheeze";
    }

    @Override
    public int getCost() {
        return pizza.getCost() + 5;
    }
}
