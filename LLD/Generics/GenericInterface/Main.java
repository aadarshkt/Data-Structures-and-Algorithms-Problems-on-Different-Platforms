package GenericInterface;

public class Main implements Shape<Circle> {



    public static void main(String[] args) {
        Main m1 = new Main();
        Circle c1 = m1.get();
        c1.print();
    }

    @Override
    public Circle get() {
        return new Circle();
    }
}
