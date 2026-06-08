package Behavioural.Template.Problem;

public class CSVParser {
    public void parse() {
        openFile();
    System.out.println("Parsing csv file");
        closeFile();
    }

    public void openFile() {
        System.out.println("Opening file");
    }

    public void closeFile() {
        System.out.println("Closing file.");
    }
}
