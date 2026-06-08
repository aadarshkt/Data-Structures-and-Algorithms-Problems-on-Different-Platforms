package Behavioural.State.Standard;

public class Client {
    public static void main(String[] args){
        Mammoth mammoth = new Mammoth();
        mammoth.observe();

        mammoth.changeState();
        mammoth.observe();

        mammoth.changeState();
        mammoth.observe();
    }
}
