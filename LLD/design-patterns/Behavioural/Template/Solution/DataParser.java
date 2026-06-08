package Behavioural.Template.Solution;

public abstract class DataParser {

    //template method.
    public final void parse() {
        openFile();
        parseData();
        closeFile();
    }

    protected void openFile() {
        System.out.println("Opening file.");
    }

    protected void closeFile() {
        System.out.println("Closing file.");
    }

    protected abstract void parseData();
}
