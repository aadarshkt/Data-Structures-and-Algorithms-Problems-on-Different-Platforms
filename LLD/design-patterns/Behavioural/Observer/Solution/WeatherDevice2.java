package Behavioural.Observer.Solution;

public class WeatherDevice2 implements Observer{
    @Override
    public void update(float temp) {
        System.out.println("The current temperature for Device 2, is " + temp + " C");
    }
}
