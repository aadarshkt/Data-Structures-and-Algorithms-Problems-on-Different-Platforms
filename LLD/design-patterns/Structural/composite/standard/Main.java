package Structural.composite.standard;

public class Main {
    public static void main(String[] args){
    LetterComposite sentence =
        new Sentence(
            new Word(
                new Letter('H'),
                new Letter('e'),
                new Letter('l'),
                new Letter('l'),
                new Letter('o')),
            new Word(
                new Letter('W'),
                new Letter('o'),
                new Letter('r'),
                new Letter('l'),
                new Letter('d')));
    sentence.print();
    }

}
