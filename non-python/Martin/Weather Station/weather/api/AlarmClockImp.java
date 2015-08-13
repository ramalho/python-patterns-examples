package api;

/**
 * This class provides the application interface 
 * for the various implementations of the 
 * alarm clock.  
 *
 * @version 1.0
 */

public interface AlarmClockImp
{
  /**
   * This will register the passed in listener to 
   * to receive the 10ms periodic updates.
   */
  void register(ClockListener listener);
}
