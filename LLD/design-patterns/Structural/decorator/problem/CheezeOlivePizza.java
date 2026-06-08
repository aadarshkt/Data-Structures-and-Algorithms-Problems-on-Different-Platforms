package Structural.decorator.problem;

//Olive pizza is tightly coupled with CheezePizza
public class CheezeOlivePizza extends CheezePizza{
    @Override
    public String getDescription() {
        return super.getDescription() + " and olives";
    }

    @Override
    public int getCost() {
        return super.getCost() + 5;
    }
}
