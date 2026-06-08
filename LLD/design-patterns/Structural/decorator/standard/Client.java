package Structural.decorator.standard;

public class Client {
    public static void main(String[] args){
        Troll simpleTroll = new SimpleTroll();

        simpleTroll.attack();
    System.out.println(simpleTroll.getAttackPower());
        simpleTroll.fleeBattle();

    System.out.println("Clubbed troll info ---- \n");

        Troll clubbedTroll = new ClubbedTroll(simpleTroll);

        clubbedTroll.attack();
        System.out.println(clubbedTroll.getAttackPower());
        clubbedTroll.fleeBattle();
  }
}
