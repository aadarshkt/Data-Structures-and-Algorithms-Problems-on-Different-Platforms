package Behavioural.Template.Solution;


public class WithTemplatePattern {
    public static void main(String[] args){
        CSVParser csvParser = new CSVParser();
        PDFParser pdfParser = new PDFParser();


        csvParser.parse();
        pdfParser.parse();
    }
}
