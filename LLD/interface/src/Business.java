public class Business implements contract1, contract2 {

    //static interface methods should have a body.

    @Override
    public void giveMoney() {

    }

    //Notice now you can enforce two specifications having single method, which you can't do with abstract.
    //Multiple inheritance is not allowed.
    @Override
    public void payTaxes() {

    }

    @Override
    public void stayHumble() {
        contract1.super.stayHumble();
    }

    @Override
    public void takeInterest() {

    }

    @Override
    public void takeMoney() {

    }

    @Override
    public void giveInterest() {

    }
}
