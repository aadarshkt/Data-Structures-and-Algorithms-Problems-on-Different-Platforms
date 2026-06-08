package Behavioural.Template.Problem;

public class PDFParser {
    public void parse() {
        openFile();
    System.out.println("Parsing pdf file");
        closeFile();
    }

    public void openFile() {
        System.out.println("Opening file");
    }

    public void closeFile() {
        System.out.println("Closing file.");
    }
}
