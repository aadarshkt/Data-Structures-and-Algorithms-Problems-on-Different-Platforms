package Structural.composite.standard;

public class Sentence extends LetterComposite{
    Sentence(Word... words) {
        for (Word word : words) {
            this.add(word);
        }
    }

    @Override
    public void printAfter() {
        System.out.print(".");
    }
}
