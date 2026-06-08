package Creational.Abstract_Factory_Pattern.Problem;

public class Application {
    public static void main(String[] args){
        //Windows UI
        WindowsButton windowsButton = new WindowsButton();
        WindowsScrollBar windowsScrollBar = new WindowsScrollBar();

        windowsButton.render();
        windowsScrollBar.render();

        //Mac UI

        //Similarly here.

        //Problems.
        //1. Tight coupling of function and objects.
        //2. No separation of concerns, Application should not care about creating objects, violates SRP
        //3. Hard to test; when testing application you would have to create other objects, instead of mocking them.
        //4. Easy to make mistake, one can add windows button with macos scrollbar.

    }
}
