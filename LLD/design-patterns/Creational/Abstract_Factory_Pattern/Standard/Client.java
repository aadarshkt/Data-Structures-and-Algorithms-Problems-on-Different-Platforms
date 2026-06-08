package Creational.Abstract_Factory_Pattern.Standard;

//The Idea is to make factory of factories.

//Step 1: Identify common objects across factories and write specification. Here -> Castle, Army, King.
//Step 2: Identify common Factory for a single group of objects Here -> Kingdom.
//Step 3: Write specification for each of the objects and their parent factory.
//Step 4: Write Factory of Factories. That will be a Factory Maker.

public class Client {
    public static void main(String[] args) {
        KingdomFactory kingdom1 = FactoryMaker.makeFactory(FactoryMaker.KingdomType.ELF);
        System.out.println(kingdom1.getArmy().getDescription());
        System.out.println(kingdom1.getCastle().getDescription());

        KingdomFactory kingdom2 = FactoryMaker.makeFactory(FactoryMaker.KingdomType.ORC);
        System.out.println(kingdom2.getKing().getDescription());

    }

}
