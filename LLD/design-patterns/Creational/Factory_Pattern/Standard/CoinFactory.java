package Creational.Factory_Pattern.Standard;

public class CoinFactory {
    public static Coin getCoin(CoinType type){
        return type.getConstructor().get();
    }
}
