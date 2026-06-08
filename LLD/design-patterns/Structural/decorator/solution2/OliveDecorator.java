package Structural.decorator.solution2;

public class OliveDecorator extends PizzaDecorator{
    public OliveDecorator(Pizza pizza) {
        super(pizza);
    }

    @Override
    public String getDescription() {
        return super.getDescription() + " and olives";
    }

    @Override
    public int getCost() {
        return super.getCost() + 7;
    }
}
