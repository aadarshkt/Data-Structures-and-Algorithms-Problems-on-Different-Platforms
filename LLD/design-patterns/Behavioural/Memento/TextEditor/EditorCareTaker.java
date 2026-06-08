package Behavioural.Memento.TextEditor;

//This is the caretaker class.

import lombok.Data;

import java.util.Stack;

@Data
public class EditorCareTaker {
    private Stack<Editor.EditorMemento> states = new Stack<>();

    //Request save.
    public void requestSave(Editor editor) {
        states.add(editor.getMemento());
    }

    //Request restore
    public void requestRestore(Editor editor) {
        if(!states.empty()){
            states.pop();
            editor.setMemento(states.peek());
        } else {
            System.out.println("Cannot undo: No previous state saved.");
        }
    }
}
