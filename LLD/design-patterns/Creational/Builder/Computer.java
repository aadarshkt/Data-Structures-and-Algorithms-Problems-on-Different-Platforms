package Creational.Builder;

public class Computer {
    private final String name;
    private final String CPU;
    private final int RAM;
    private final int ROM;
    private final int battery;


    public Computer(Builder builder) {
        this.name = builder.name;
        this.CPU = builder.CPU;
        this.RAM = builder.RAM;
        this.ROM = builder.ROM;
        this.battery = builder.battery;
    }

    @Override
    public String toString() {
        return "Computer{" +
                "name='" + name + '\'' +
                ", CPU='" + CPU + '\'' +
                ", RAM=" + RAM +
                ", ROM=" + ROM +
                ", battery=" + battery +
                '}';
    }

    //You can also make this builder class independent, but since it is related to
    //the current class, you can keep it here as well.
    //Nothing will happeng actually if you remove static.
    public static class Builder {
        private final String name;
        private final String CPU;
        private int RAM = 8;
        private int ROM = 8;
        private int battery = 8;

        //Required parameters
        public Builder(String name, String CPU){
            this.name = name;
            this.CPU = CPU;
        }

        //Optional Parameters.
        public Builder addRAM(int RAM){
            this.RAM = RAM;
            return this;
        }

        public Builder addROM(int ROM){
            this.ROM = ROM;
            return this;
        }

        public Builder addBattery(int battery){
            this.battery = battery;
            return this;
        }

        //Kind of copy constructor
        public Computer build(){
            return new Computer(this);
        }
    }
}
