package Creational.Abstract_Factory_Pattern.Standard;

//Similarly, you can create another king dom factory.
public class ElfKingdomFactory implements KingdomFactory
{
    @Override
    public Castle getCastle() {
        return new ElfCastle();
    }

    @Override
    public Army getArmy() {
        return new ElfArmy();
    }

    @Override
    public King getKing() {
        return new ElfKing();
    }
}
