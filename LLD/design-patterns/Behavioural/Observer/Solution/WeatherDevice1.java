package Behavioural.Observer.Solution;

public class WeatherDevice1 implements Observer{
    @Override
    public void update(float temp) {
        System.out.println("The current temperature for Device 1, is " + temp + " C");
    }
}
