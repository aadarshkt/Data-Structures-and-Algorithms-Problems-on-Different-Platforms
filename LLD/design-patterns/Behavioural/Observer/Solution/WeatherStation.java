package Behavioural.Observer.Solution;

import java.util.ArrayList;
import java.util.List;

public class WeatherStation implements Subject{
    private float temp;
    private final List<Observer> observerList;

    public WeatherStation() {
        this.observerList = new ArrayList<Observer>();
        this.temp = 20.0f;
    }

    @Override
    public void addObserver(Observer observer) {
        observerList.add(observer);
    }

    @Override
    public void removeObserver(Observer observer) {
        observerList.remove(observer);
    }

    @Override
    public void notifyObservers() {
        for(Observer observer : observerList) {
            observer.update(this.temp);
        }
    }

    //make temperature dynamic
    public void towardsDay() {
        this.temp += 2.0f;
        notifyObservers();
    }
    public void towardsNight() {
        this.temp -= 2.0f;
        notifyObservers();
    }
}
