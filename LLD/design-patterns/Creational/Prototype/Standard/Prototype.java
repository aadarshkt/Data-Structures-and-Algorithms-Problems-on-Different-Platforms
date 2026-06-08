package Creational.Prototype.Standard;

import lombok.SneakyThrows;

abstract class Prototype<T> implements Cloneable {

    @SneakyThrows
    @SuppressWarnings("unchecked")
    public T copy() {
        return (T) super.clone();
    }
}

//now use this class to extend any class and call its copy method to return a copy.