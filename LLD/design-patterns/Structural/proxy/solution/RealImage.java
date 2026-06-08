package Structural.proxy.solution;

public class RealImage implements Image {

    private final String fileName;

    public RealImage(String fileName) {
        this.fileName = fileName;
        loadFromDisk();
    }

    private void loadFromDisk() {
        System.out.println("Expensive loading operation");
    }


    @Override
    public void display() {
        System.out.println("Displaying Image onto the screen " + fileName);
    }
}

