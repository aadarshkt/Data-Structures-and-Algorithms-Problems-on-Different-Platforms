public interface contract1 {
    void giveMoney();
    void giveInterest();
    void payTaxes();
    default void stayHumble() {
        System.out.println("I am humble");
    }
}
