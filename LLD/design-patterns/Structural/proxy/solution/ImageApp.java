package Structural.proxy.solution;

public class ImageApp {
    public static void main(String[] args){
        Image img1 = new ProxyImage("Dog.png"); //Now no loading operation is there.
        Image img2 = new ProxyImage("Cat.png");

        img1.display(); //Now loading when actual display is happening.

        //Solutions
        /*
        1. Caching - calling same object every time.
        2. Lazy loading - loading when actually needed to show the image info in binary.
         */
    }
}
