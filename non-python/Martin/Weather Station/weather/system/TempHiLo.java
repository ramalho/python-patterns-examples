package system;

import java.util.Observer;
import java.util.Observable;
import java.util.Date;

import wmsdata.HiLoData;

public class TempHiLo
{
  private AlarmClock itsAlarmClock;
  private TemperatureSensor itsSensor;
  private HiLoData itsData;

  public TempHiLo(TemperatureSensor theSensor,
                  AlarmClock theAlarmClock)
  {
    itsAlarmClock = theAlarmClock;
    itsSensor = theSensor; 
    
    // construct the data object
    Date d = new Date();
    double sensorValue = itsSensor.read();
    itsData = wmsdata.Scope.itsDataToolkit.getTempHiLoData(d, sensorValue);

    // register for the 24 hour data
    AlarmListener al = new AlarmListener()
    {
      public void wakeUp()
      {
        newDay();
      }
    };
    itsAlarmClock.wakeEveryDay(al);

    // register for changes in the sensor
    Observer o = new Observer()
    {
      public void update(Observable ob, Object anObject)
      {
        Double val = (Double)anObject;
        itsData.currentReading(val.doubleValue(), 
                               System.currentTimeMillis());
      }
    };
    itsSensor.addObserver(o);
  }

  private void newDay()
  {
    double val = itsSensor.read();
    long time = System.currentTimeMillis();

    itsData.newDay(val, time);
  }
}
