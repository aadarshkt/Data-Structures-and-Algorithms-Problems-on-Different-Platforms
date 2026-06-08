package Behavioural.Command.Standard;

public class Client {
    public static void main(String[] args){
        Wizard wizard = new Wizard();
        Goblin goblin = new Goblin();

        wizard.castSpell(goblin::growSize, goblin::shrinkSize);
        wizard.castSpell(goblin::shrinkSize, goblin::growSize);

        wizard.undoLastSpell();
        wizard.redoLastSpell();
    }
}
