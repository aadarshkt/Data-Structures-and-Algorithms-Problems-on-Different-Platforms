package Behavioural.Command.Restaurant;

import lombok.Setter;

// Concrete Command
// In object-oriented programming, the command pattern is
// a behavioral design pattern in which an object is used to encapsulate
// all information needed to perform an action or trigger an event at a later time.
@Setter
public class MakeBurgerCommand implements Command {

    private Chef chef;

    @Override
    public void execute() {
        chef.makeBurger();
    }
}
