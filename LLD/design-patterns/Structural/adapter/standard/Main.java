package Structural.adapter.standard;

public class Main {
    public static void main(String[] args){
    Captain captain = new Captain(new FishingBoatAdapter());

    captain.row();
    }
}
