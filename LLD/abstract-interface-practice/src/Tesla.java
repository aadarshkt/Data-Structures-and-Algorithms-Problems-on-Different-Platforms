public class Tesla extends Car implements ElectricCar {
    public Tesla(String brand){
        super(brand);
    }


    @Override
    public void chargeBattery() {
        System.out.println("Charging Battery");
    }
}
