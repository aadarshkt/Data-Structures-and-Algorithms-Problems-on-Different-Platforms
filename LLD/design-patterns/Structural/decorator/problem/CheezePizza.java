package Structural.decorator.problem;

public class CheezePizza extends SimplePizza{
    @Override
    public String getDescription() {
        return super.getDescription() + " and added cheeze";
    }

    @Override
    public int getCost() {
        return super.getCost() + 5;
    }
}
