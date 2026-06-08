package Creational.Prototype.Standard;

public class Client {
    public static void main(String[] args){
        var factory = new HeroFactoryImpl(new OrcMage("Indra", 100), new OrcBeast("Devil", 2));

        var mageCopy = factory.createMage();
        var beastCopy = factory.createBeast(); //Use prototype pattern.

  }
}
