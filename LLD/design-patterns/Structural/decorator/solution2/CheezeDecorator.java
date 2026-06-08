package Structural.decorator.solution2;

public class CheezeDecorator extends PizzaDecorator{
    public CheezeDecorator(Pizza pizza) {
        super(pizza);
    }

    @Override
    public String getDescription() {
        return super.getDescription() + " and cheeze";
    }

    @Override
    public int getCost() {
        return super.getCost() + 5;
    }
}
