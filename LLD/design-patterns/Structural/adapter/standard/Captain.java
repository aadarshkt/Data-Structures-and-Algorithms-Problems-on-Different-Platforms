package Structural.adapter.standard;

public class Captain {
    RowingBoat rowingBoat;

    Captain(RowingBoat rowingBoat) {
        this.rowingBoat = rowingBoat;
    }

    public void row() {
        rowingBoat.row();
    }
}
