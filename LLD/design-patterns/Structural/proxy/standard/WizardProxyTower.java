package Structural.proxy.standard;

public class WizardProxyTower implements WizardTower{


    private final WizardTower wizardTower;
    private static final int MAX_NUM_WIZARDS = 3;
    private int numWizards;

    public WizardProxyTower(WizardTower wizardTower) {
        this.wizardTower = wizardTower;
    }

    @Override
    public void enter(Wizard wizard) {
        if(numWizards < MAX_NUM_WIZARDS) {
            wizardTower.enter(wizard);
            numWizards++;
        } else {
            System.out.println("Enough wizards no more wizards allowed now!");
        }
    }
}
