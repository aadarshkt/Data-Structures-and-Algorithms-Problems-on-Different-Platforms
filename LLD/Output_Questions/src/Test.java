
//since greet is static methods and resolved at compile time.
//so at compile time object child is not available.
//So it binds with Parent reference type.

//Instance methods → runtime binding (polymorphism).
//
//Static methods → compile-time binding (method hiding).
public class Test {
    public static void main(String[] args) {
        Parent p = new Child();
        p.greet();
    }
}
