package Structural.decorator.problem;

/*
Problems - 1.  Class explosion.
2. Not scalable.
3. Maintainability and scalability.
 */
public class PizzaApp {
    public static void main(String[] args){
        Pizza cheezeOlivePizza = new CheezeOlivePizza();

        System.out.println(cheezeOlivePizza.getDescription());
        System.out.println(cheezeOlivePizza.getCost());
    }
}
