package Behavioural.Observer.Problem;

import lombok.Setter;

@Setter
public class WeatherStation {
    private float temp;

    //Tight coupling with devices, hard to add more devices.
    public void notifyDevices(WeatherDevice weatherDevice) {
        weatherDevice.showTemp(this.temp);
    }

}
