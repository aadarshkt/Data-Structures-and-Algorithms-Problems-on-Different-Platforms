package Creational.Prototype.Standard;

import lombok.RequiredArgsConstructor;

@RequiredArgsConstructor
public class HeroFactoryImpl implements HeroFactory{

    private final Mage mage;
    private final Beast beast;

    @Override
    public Mage createMage() {
        return mage.copy(); //Using prototype pattern.
    }

    @Override
    public Beast createBeast() {
        return beast.copy();
    }
}
