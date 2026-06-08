public class Square extends Shapes {
    void area(){
        System.out.println("The area of Square is side squared");
    }

    //1. static methods cannot be overridden
//    @Override
//    static void print(){
//        System.out.println("I am square");
//    }

    static void print(){
        System.out.println("I am square");
    }
}
