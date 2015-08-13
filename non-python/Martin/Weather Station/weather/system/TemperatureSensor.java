package system;

/**
 * These are the imports from the weather station classes for
 * the Temperature class.
 */
import api.StationToolkit;
import api.TemperatureSensorImp;

/**
 * These are imports required from the Java class libraries
 */
import java.util.Observable;

/**
 * The Temperature class is the abstraction that is used by the
 * application software.  It hides it's platform specific implementation
 * in the TemperatureSensorImp variable.  The implementation is created by
 * this class using the passed in StationToolkit.  This class also
 * registers itself (as a AlarmListener) with the AlarmClock in order
 * to get it's periodic updates.  When it is notified of this update it
 * determines if the value has changed and if so it notifies the
 * classes that have registered themselves as Observers of this class
 * of the value change.
 *
 * @version 1.0
 */

public class TemperatureSensor extends Observable
{
  private TemperatureSensorImp itsImp;
  private double itsLastReading = Double.NaN;

  /**
   * This function performs the check to see of the temperature
   * has changed and if so notifies the observers.
   */
  private void check()
  {
    System.out.println("In check");
    double newTemperature = read();

    if(itsLastReading != newTemperature)
    {
      itsLastReading = newTemperature;
      setChanged();
      notifyObservers(new Double(itsLastReading));
    }
  }

  public TemperatureSensor(StationToolkit theToolkit, 
                           AlarmClock theAlarmClock)
  {
    itsImp = theToolkit.makeTemperature();
    
    // create the anonymous object that will answer for the 
    // timer observer
    AlarmListener observer = new AlarmListener()
    {
      public void wakeUp()
      {
        check();
      }
    };

    // register with the timer for every second
    theAlarmClock.wakeEvery(1000, observer);
  }

  /**
   * @return the temperature in degrees Celcius
   */
  public double read()
  {
    return itsImp.read();
  }
}
