package Behavioural.Memento.TextEditor;

import java.util.Objects;

public class Client {
    public static void main(String[] args){
        Editor editor = new Editor();
        EditorCareTaker editorCareTaker = new EditorCareTaker();
        editor.setText("Hello World");
        editorCareTaker.requestSave(editor);
        editor.setText("Hello Earth");

        editorCareTaker.requestSave(editor);

        editorCareTaker.requestRestore(editor);

        System.out.println(editor.getText());
    }
}
