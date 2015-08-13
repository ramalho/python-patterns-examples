package api;

/**
 * @see AlarmClockImp
 * @version 1.0
 */

public interface ClockListener
{
  /** 
   * This method will be called every 10ms.
   */
  public void tic();
}
