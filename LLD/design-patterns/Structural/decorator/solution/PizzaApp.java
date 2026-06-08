package Structural.decorator.solution;

/*
Benefits
1. You can add any decorator in any order, since the Constructor is generalized Pizza
2. No tight coupling
 */
public class PizzaApp {
    public static void main(String[] args){
        Pizza pizza = new SimplePizza();
        Pizza cheesePizza = new CheezeDecorator(pizza);
        Pizza cheeseOlivePizza = new OliveDecorator(cheesePizza);

    System.out.println(cheeseOlivePizza.getDescription());
    System.out.println(cheeseOlivePizza.getCost());
  }
}
