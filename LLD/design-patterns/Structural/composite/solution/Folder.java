package Structural.composite.solution;

import java.util.ArrayList;
import java.util.List;

public class Folder implements FileComposite {

    String FolderName;
    int FolderSize;

    List<FileComposite> components = new ArrayList<>();

    public Folder(String folderName) {
        this.FolderName = String.valueOf(folderName);
    }

    public void addComponent(FileComposite fileComposite) {
        components.add(fileComposite);
    }

    @Override
    public int getSize() {
        for(FileComposite fileComposite : components) {
            // Logic to calculate folder size can be added here
            FolderSize += fileComposite.getSize();
        }
        return FolderSize;
    }

    @Override
    public void showDetails() {
        System.out.println("Folder Name: " + FolderName + ", Size: " + this.getSize() + "KB");
        for(FileComposite fileComposite : components) {
            System.out.print(" |");
            System.out.print("---");
            fileComposite.showDetails();
        }
    }
}
