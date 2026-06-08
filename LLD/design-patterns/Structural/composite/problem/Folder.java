package Structural.composite.problem;

import lombok.Getter;

import java.util.ArrayList;
import java.util.List;

public class Folder {
    @Getter
    private String name;

    //What if there are sub folders?
    //We would need to change this to List<Object> or List<FileSystemComponent>
    //which would violate the OCP principle.
    //This is the main problem that Composite pattern solves.

    List<File> files = new ArrayList<>();

    public Folder(String name) {
        this.name = name;
    }

    public void addFile(File file) {
        files.add(file);
    }

    public void showDetails() {
        System.out.println("Folder Name: " + name);
        files.forEach(File::showDetails);
    }
}
