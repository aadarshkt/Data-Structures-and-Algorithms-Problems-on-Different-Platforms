package Structural.composite.problem;

public class File {
    String name;

    File(String name){
        this.name = name;
    }



    public void showDetails() {
        System.out.println("File Name: " + name);
    }
}
