package Creational.Factory_Pattern.Standard;

//This client needs different objects types.
public class Client {

    public static void main(String[] args) {
        Coin c1 = CoinFactory.getCoin(CoinType.COPPER);
        Coin c2 = CoinFactory.getCoin(CoinType.GOLD);


        System.out.println(c1.getDescription());
        System.out.println(c2.getDescription());
    }
}
