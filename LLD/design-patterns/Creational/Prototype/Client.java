package Creational.Prototype;

public class Client {
    public static void main(String[] args){
        Shape s1 = new Shape(40, "Triangle", "40");

        //Use case -> You don't have to know what are the parameters.
        //Those parameters may be coming after long computation so you are just copying
        //them.
        Shape s2 = s1.clone();
        System.out.println(s2.getArea());
    }
}
