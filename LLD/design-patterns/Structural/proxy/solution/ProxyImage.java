package Structural.proxy.solution;

public class ProxyImage implements Image{

    private String fileName;
    private RealImage realImage;

    ProxyImage(String fileName) {
        this.fileName = fileName;
        System.out.println("No expensive loading now");
    }

    @Override
    public void display() {
        if(realImage == null) {
            realImage = new RealImage(this.fileName);
        }
        realImage.display();
    }
}
