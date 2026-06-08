public class CreditCard extends Card {
    public CreditCard(String cardNo, String userName) {
        super(cardNo, userName);
    }

    public static String cardType = "Axis bank";

    public static void printCardNo(){
        System.out.println("Card class");
    }

    public static void print(){
        System.out.println("New card");
    }
}
