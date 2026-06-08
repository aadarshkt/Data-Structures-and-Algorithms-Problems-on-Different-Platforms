package Structural.proxy.problem;

public class ImageApp {
    public static void main(String[] args){
        Image img1 = new RealImage("Dog.png");
        Image img2 = new RealImage("cat.png"); //Loaded when literally not used

        img1.display();
        img1.display(); //No caching - I don't believe it. Same heavy object is there in second call also.


    }
}
