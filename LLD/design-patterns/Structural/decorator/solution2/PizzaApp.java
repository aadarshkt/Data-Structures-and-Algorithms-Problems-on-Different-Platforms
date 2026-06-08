package Structural.decorator.solution2;

public class PizzaApp {
    public static void main(String[] args){
        Pizza simplePizza = new SimplePizza();

        Pizza cheezePizza = new CheezeDecorator(simplePizza);
        Pizza oliveAndCheezePizza = new OliveDecorator(cheezePizza);

    System.out.println(oliveAndCheezePizza.getDescription());
    System.out.println(oliveAndCheezePizza.getCost());
  }
}
