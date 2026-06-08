package Behavioural.Observer.Problem;

public class WithoutObserverPattern {
    public static void main(String[] args){
        WeatherStation weatherStation = new WeatherStation();
        WeatherDevice weatherDevice = new WeatherDevice();

        weatherStation.setTemp(16.1f);
        weatherStation.notifyDevices(weatherDevice); //Manually notify each device.
        //Hard to scale to more devices.
        weatherStation.setTemp(15.1f);
        weatherStation.notifyDevices(weatherDevice);
    }
}
