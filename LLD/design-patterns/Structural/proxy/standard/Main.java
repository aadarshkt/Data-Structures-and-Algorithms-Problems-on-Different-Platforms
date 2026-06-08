package Structural.proxy.standard;

public class Main {
    public static void main(String[] args){
        WizardTower proxyTower = new WizardProxyTower(new IvoryTower());

        proxyTower.enter(new Wizard("Wizard 1"));
        proxyTower.enter(new Wizard("Wizard 2"));
        proxyTower.enter(new Wizard("Wizard 3"));
        proxyTower.enter(new Wizard("Wizard 4"));
        proxyTower.enter(new Wizard("Wizard 5"));

    }
}
