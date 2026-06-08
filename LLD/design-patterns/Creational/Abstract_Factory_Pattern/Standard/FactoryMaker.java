package Creational.Abstract_Factory_Pattern.Standard;


//Factory of Factories
public class FactoryMaker {
    public enum KingdomType {
       ELF, ORC
    }

    public static KingdomFactory makeFactory(KingdomType type){
        return switch (type) {
            case ELF -> new ElfKingdomFactory();
            case ORC -> new OrcKingdomFactory();
        };
    }
}
