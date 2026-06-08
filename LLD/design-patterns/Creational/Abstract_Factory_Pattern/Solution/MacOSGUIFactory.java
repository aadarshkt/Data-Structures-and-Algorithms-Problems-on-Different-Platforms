package Creational.Abstract_Factory_Pattern.Solution;

public class MacOSGUIFactory implements GuiFactory{
    @Override
    public Button createButton() {
        return new MacOSButton();
    }

    @Override
    public ScrollBar createScrollBar() {
        return new MacOSScrollBar();
    }
}
