package Creational.Factory_Pattern.Solution;

public class TransportFactory {
    public static Transport createTransport(String type) {
        return switch (type) {
            case "car" -> new Car();
            case "bike" -> new Bike();
            case "bus" -> new Bus();
            default -> throw new IllegalArgumentException("Arguments is not known");
        };
    }
}
