package ui;

import component.WeatherStationComponent;
import java.util.Observer;
import java.util.Observable;

public class MonitoringScreen
{
  public MonitoringScreen(WeatherStationComponent wsc)
  {
    // register the observers of the changes in the sensors
    Observer tempObserver = new Observer()
    {
      public void update(Observable observable, Object obj)
      {
        Double d = (Double)obj;
        temperatureChange(d.doubleValue());
      }
    };
    wsc.addTempObserver(tempObserver); 

    Observer pressureObserver = new Observer()
    {
      public void update(Observable observable, Object obj)
      {
        Double d = (Double)obj;
        pressureChange(d.doubleValue());
      }
    };
    wsc.addBPObserver(pressureObserver); 
  }

  private void temperatureChange(double value)
  {
    System.out.println("Temperature: " + value);
  }

  private void pressureChange(double value)
  {
    System.out.println("BP: " + value);
  }
}
