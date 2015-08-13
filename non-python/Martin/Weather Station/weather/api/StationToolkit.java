package api;

/**
 * The StationToolkit serves as the focal point for the 
 * creation of the platform independant application objects.
 * All of the return types of this factory are interfaces.  The
 * actual implementation is provided in a derived class which 
 * is platform specific.
 *
 * @see AlarmClockImp
 * @see PersistentImp
 * @see TemperatureImp
 * @see BarometricPressureSensorImp
 * @version 1.0
 */

public interface StationToolkit
{
  PersistentImp getPersistentImp();
  AlarmClockImp getAlarmClock();
  TemperatureSensorImp makeTemperature();
  BarometricPressureSensorImp makeBarometricPressure();
}
