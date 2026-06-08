package Structural.proxy.standard;

public class Wizard {
    private final String name;

    Wizard(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Wizard{" +
                "name='" + name + '\'' +
                '}';
    }
}
