public class Human {
    String name;
    static int population;

    public Human(String name){
        this.name = name;
        this.population += 1;
    }
}
