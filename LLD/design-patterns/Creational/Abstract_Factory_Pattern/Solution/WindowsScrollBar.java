package Creational.Abstract_Factory_Pattern.Solution;

public class WindowsScrollBar implements ScrollBar{
    @Override
    public void render() {
        System.out.println("Rendering windows scrollbar");
    }
}
