package system;

import java.util.Hashtable;

import api.StationToolkit;
import api.ClockListener;
import api.AlarmClockImp;

/**
 * 
 * @see AlarmListener
 * @version 1.0
 */

public class AlarmClock
{
  private AlarmClockImp itsImp;
  private Hashtable itsListeners;

  private void clockPulse()
  {
    // This will be called every 10ms.

    // determine if anyone registered needs to be 
    // informed
  }

  public AlarmClock(StationToolkit st)
  {
    itsImp = st.getAlarmClock();

    ClockListener cl = new ClockListener()
    {
      public void tic()
      {
        clockPulse();
      }
    };
    itsImp.register(cl);

    itsListeners = new Hashtable();
  }

  /** 
   * register to be notified every period.  The value passed 
   * in is in milleseconds.
   **/ 
  public void wakeEvery(long period, AlarmListener al)
  {
    itsListeners.put(al,new Long(period)); 
  }

  /**
   * register to be notified every hour on the hour
   */
  public void wakeEveryHour(AlarmListener al)
  {
  }

  /** 
   * register to be notified every day at midnight 
   **/
  public void wakeEveryDay(AlarmListener al)
  {
  }
}
