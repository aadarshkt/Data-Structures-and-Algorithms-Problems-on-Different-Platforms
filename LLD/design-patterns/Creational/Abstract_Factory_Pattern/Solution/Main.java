package Creational.Abstract_Factory_Pattern.Solution;


public class Main {
    public static void main(String[] args){
        //Ask for it.
        Application application = new Application(new WindowsGUIFactory());

        application.render();


        //Very easy to change
//        Application application = new Application (new MacOSGUIFactory());
//
//        application.render();
    }
}
