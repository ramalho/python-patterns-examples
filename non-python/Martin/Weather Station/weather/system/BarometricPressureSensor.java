package system;

/**
 * These are the imports from the weather station classes for
 * the Temperature class.
 */
import api.StationToolkit;
import api.BarometricPressureSensorImp;

/**
 * These are imports required from the Java class libraries
 */
import java.util.Observable;

/**
 * The BarometricPressure class is the abstraction that is used by the
 * application software.  It hides it's platform specific implementation
 * in the BarometricPressureSensorImp variable.  The implementation is 
 * created by this class using the passed in StationToolkit.  This class 
 * also registers itself (as a AlarmListener) with the AlarmClock in order
 * to get it's periodic updates.  When it is notified of this update it
 * determines if the value has changed and if so it notifies the
 * classes that have registered themselves as Observers of this class
 * of the value change. 
 *
 * @author James Newkirk
 * @version 1.0
 */

public class BarometricPressureSensor extends Observable
{
  private BarometricPressureSensorImp itsImp;
  private double itsLastReading;

  private void check()
  {
    double currentPressure = read();
    if(currentPressure != itsLastReading)
    {
      Double pressure = new Double(currentPressure);
      setChanged();
      notifyObservers(pressure);
    }
  }

  /** 
   * The constructor for Barometric Pressure takes the following 
   * parameters. 
   * @param StationToolkit in order to create the implementation class
   * @param AlarmClock in order to register for timer updates
   *
   */
  public BarometricPressureSensor(StationToolkit theToolkit, 
                                  AlarmClock theAlarmClock)
  {
    itsImp = theToolkit.makeBarometricPressure();

    // create the anonymous object that will answer for the 
    // AlarmListener 
    AlarmListener listener = new AlarmListener()
    {
      public void wakeUp()
      {
        check();
      }
    };

    // register with the timer for every 5 seconds
    theAlarmClock.wakeEvery(5000, listener);
  }

  /**
   * @return current barometric pressure reading in inches of mercury 
   */
  public double read()
  {
    return itsImp.read();
  }
}
