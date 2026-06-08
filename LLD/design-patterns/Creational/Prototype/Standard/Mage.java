package Creational.Prototype.Standard;

import lombok.RequiredArgsConstructor;

@RequiredArgsConstructor
public abstract class Mage extends Prototype<Mage>{
    private final String name;
    private final int power;
}
