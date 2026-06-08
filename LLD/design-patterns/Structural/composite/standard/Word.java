package Structural.composite.standard;

public class Word extends LetterComposite{

    Word(Letter... letters) {
        for (Letter letter : letters) {
            this.add(letter);
        }
    }

    @Override
    public void printAfter() {
        System.out.print(" ");
    }
}
