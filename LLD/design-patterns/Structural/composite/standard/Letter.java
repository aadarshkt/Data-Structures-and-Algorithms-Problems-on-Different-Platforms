package Structural.composite.standard;

public class Letter extends LetterComposite{
    private final char character;

    public Letter(char character) {
        this.character = character;
    }

    @Override
    protected void printBefore() {
        System.out.print(character);
    }

    @Override
    protected void printAfter() {
        // No action needed after printing a letter
    }
}
