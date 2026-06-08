package Structural.adapter.standard;

public class FishingBoatAdapter implements RowingBoat{

    FishingBoat fishingBoat;

    FishingBoatAdapter() {
        this.fishingBoat = new FishingBoat();
    }
    @Override
    public void row() {
        fishingBoat.sail();
    }
}
