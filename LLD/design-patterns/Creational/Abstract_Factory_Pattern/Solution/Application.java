package Creational.Abstract_Factory_Pattern.Solution;

//We can write this general purpose application.
public class Application {
    Button button;
    ScrollBar scrollBar;
    public Application(GuiFactory guiFactory) {
        this.button = guiFactory.createButton();
        this.scrollBar = guiFactory.createScrollBar();
    }

    public void render(){
        button.render();
        scrollBar.render();
    }
}
