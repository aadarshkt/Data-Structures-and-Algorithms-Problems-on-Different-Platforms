package Behavioural.Command.Standard;

//Receiver -- Will contain logic to do things.
public class Goblin {
    private int size = 1;

    public void growSize() {
        size++;
        System.out.println("The current size of goblin is " + size);
    }

    public void shrinkSize() {
        size--;
        System.out.println("The current size of goblin is " + size);
    }
}
