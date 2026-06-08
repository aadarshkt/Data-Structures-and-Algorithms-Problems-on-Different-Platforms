package Creational.Prototype.Standard;

import lombok.RequiredArgsConstructor;

@RequiredArgsConstructor
public abstract class Beast extends Prototype<Beast>{
    private final String name;
    private final int power;
}
