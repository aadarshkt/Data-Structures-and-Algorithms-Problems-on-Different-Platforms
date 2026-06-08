package Structural.composite.solution;

public class Main {
    public static void main(String[] args){
        File file1 = new File("File1.txt", 100);

        File file2 = new File("File2.txt", 200);

        Folder folder = new Folder("MyFolder");
        folder.addComponent(file1);
        folder.addComponent(file2);

        Folder subFolder = new Folder("SubFolder");
        File file3 = new File("File3.txt", 300);
        subFolder.addComponent(file3);

        folder.addComponent(subFolder);

        folder.showDetails();
    }
}
