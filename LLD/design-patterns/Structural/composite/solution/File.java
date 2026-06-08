package Structural.composite.solution;

public class File implements FileComposite {
    String name;
    int size;

    File(String name, int size){
        this.name = name;
        this.size = size;
    }

    @Override
    public void showDetails() {
        System.out.println("File Name: " + name + ", Size: " + size + "KB");
    }

    @Override
    public int getSize() {
        return size;
    }
}
