package Behavioural.Memento.TextEditor;

//This is an originator

import lombok.Data;

@Data
public class Editor {
    private String text;

    //Request save //Request Memento //Request snapshot to save in stack.
    public EditorMemento getMemento() {
        var state = new EditorMemento();
        state.text = this.text;
        return state;
    }

    //Request Restore //setMemento
    public void setMemento(EditorMemento editorMemento) {
        this.text = editorMemento.text;
    }

    public static class EditorMemento {
        private String text;
    }
}
