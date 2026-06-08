public interface contract2 {
    void takeMoney();
    void takeInterest();
    void payTaxes();
    default void stayHumble() {
        System.out.println("I am humble");
    }
}
