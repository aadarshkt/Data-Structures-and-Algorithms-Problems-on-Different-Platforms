package Structural.composite.standard;

import java.util.ArrayList;
import java.util.List;

public abstract class LetterComposite {
    private final List<LetterComposite> list = new ArrayList<>();

    public void add(LetterComposite letterComposite) {
        list.add(letterComposite);
    }

    protected void printBefore() {

    }

    protected void printAfter() {

    }

    public void print() {
        printBefore();
        list.forEach(LetterComposite::print);
        printAfter();
    }
}
