//class
public class Shapes {
    //final void area(){} cannot be overridden //Called early binding

    //final classes cannot be inherited.
    int area1;
    void area() {
        System.out.println("Area of shape");
    }

    static void print(){
        System.out.println("I am a shape");
    }
}
