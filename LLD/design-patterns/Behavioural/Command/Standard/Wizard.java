package Behavioural.Command.Standard;

//Command interface is used as Runnable interface.

import java.util.Deque;
import java.util.LinkedList;

//Invoker -- will use runnable.run()
public class Wizard {
    private final Deque<Runnable> undoStack = new LinkedList<>();
    private final Deque<Runnable> redoStack = new LinkedList<>();

    public void castSpell(Runnable doAction, Runnable undoAction) {
        doAction.run();
        undoStack.push(undoAction);
        redoStack.clear();
    }

    public void undoLastSpell() {
        if(!undoStack.isEmpty()) {
            Runnable undoAction = undoStack.pop();
            undoAction.run();
            redoStack.push(undoAction);
        } else {
            System.out.println("Nothing to undo!");
        }
    }

    public void redoLastSpell() {
        if(!redoStack.isEmpty()) {
            Runnable redoAction = redoStack.pop();
            redoAction.run();
        } else {
            System.out.println("Nothing to redo!");
        }
    }
}
