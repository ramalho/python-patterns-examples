package api;

/**
 * This class provides the application interface 
 * for the various implementations of the 
 * temperature sensor.  
 *
 * @version 1.0
 */

public interface TemperatureSensorImp
{
  /**
   * @return The temperature in degrees Celcius
   */
  public double read();
}
