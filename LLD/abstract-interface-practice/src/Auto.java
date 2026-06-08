public class Auto extends Vehicle {
    public Auto(String brand){
        super(brand);
    }

    @Override
    void drive() {
        System.out.println("Implementation of driving of Auto");
    }
}
