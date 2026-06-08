package Structural.proxy.standard;

public class IvoryTower implements WizardTower{
    @Override
    public void enter(Wizard wizard) {
        System.out.println("This Wizard has entered " + wizard.getName());
    }
}
