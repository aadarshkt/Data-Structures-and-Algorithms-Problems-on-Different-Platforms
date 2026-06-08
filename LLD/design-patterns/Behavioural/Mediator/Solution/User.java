package Behavioural.Mediator.Solution;

import lombok.Data;

//Colleague
public abstract class User {
    protected Mediator mediator;

    protected String name;

    User(Mediator mediator, String name) {
        this.mediator = mediator;
        this.name = name;
    }

    abstract void send(String message);
    abstract void receive(String message);
}
