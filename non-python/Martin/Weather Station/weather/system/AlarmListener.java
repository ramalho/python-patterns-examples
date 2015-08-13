package system;

/**
 * The AlarmListener interface is used by the users of 
 * the AlarmClock interface.  If a class wishes to be notified 
 * using the AlarmClock, the class will have to implement this
 * interface and register with the AlarmClock specifying this 
 * object and a duration.
 *
 * @see AlarmClock
 * @version 1.0
 */

public interface AlarmListener
{
  void wakeUp();
}
