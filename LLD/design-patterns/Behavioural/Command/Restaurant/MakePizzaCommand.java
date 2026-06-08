package Behavioural.Command.Restaurant;

import lombok.Setter;

@Setter
public class MakePizzaCommand implements Command{

    private Chef chef;
    @Override
    public void execute() {
        chef.makePizza();
    }
}
