package Creational.Abstract_Factory_Pattern.Standard;

public class OrcKingdomFactory implements KingdomFactory{
    @Override
    public Castle getCastle() {
        return new OrcCastle();
    }

    @Override
    public Army getArmy() {
        return new OrcArmy();
    }

    @Override
    public King getKing() {
        return new OrcKing();
    }
}
