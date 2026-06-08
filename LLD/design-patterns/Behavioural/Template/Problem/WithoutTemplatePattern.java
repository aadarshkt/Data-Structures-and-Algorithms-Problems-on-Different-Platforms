package Behavioural.Template.Problem;

public class WithoutTemplatePattern {
    public static void main(String[] args){
        CSVParser csvParser = new CSVParser();
        PDFParser pdfParser = new PDFParser();

        csvParser.parse();
        pdfParser.parse();
    }
}
