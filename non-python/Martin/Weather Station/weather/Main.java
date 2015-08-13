
import java.util.Observer;
import java.util.Observable;

import api.StationToolkit;
import system.WeatherStation;
import ui.MonitoringScreen;

class Main 
{
  public static void main(String[] args)
  {
    try
    {
      persistence.Scope.init();

      WeatherStation ws = new WeatherStation(args[0]);
      MonitoringScreen ms = new MonitoringScreen(ws);
      for(;;) 
      {
        // loop forever
      }
    }
    catch(Exception e)
    {
      System.err.println(args[0] + " Invalid Toolkit");
    }
  }
}
