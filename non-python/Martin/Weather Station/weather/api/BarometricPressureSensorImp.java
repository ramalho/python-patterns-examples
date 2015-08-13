package api;

/**
 * This class provides the application interface for 
 * the various implementations of the barometric 
 * pressure sensor.  
 *
 * @version 1.0
 */

public interface BarometricPressureSensorImp
{
  /**
   * @return barometric pressure in inches of mercury 
   */
  public double read();
}
