package Behavioural.Observer.Solution;

import Behavioural.Observer.Solution.WeatherStation;

public class Client {
    public static void main(String[] args){
        WeatherStation weatherStation = new WeatherStation();
        WeatherDevice1 weatherDevice1 = new WeatherDevice1();
        WeatherDevice2 weatherDevice2 = new WeatherDevice2();

        weatherStation.addObserver(weatherDevice1);
        weatherStation.addObserver(weatherDevice2);

        weatherStation.towardsDay();
        weatherStation.removeObserver(weatherDevice1);
        weatherStation.towardsNight();
    }
}
