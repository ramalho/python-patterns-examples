package test;

import api.*;

public class Toolkit implements StationToolkit
{
  private static AlarmClockImp itsClockImp = new test.AlarmClockImp();
  private static PersistentImp itsPersistentImp = new PersistentImp();

  public api.PersistentImp getPersistentImp()
  {
    return itsPersistentImp;
  }

  public api.AlarmClockImp getAlarmClock()
  {
    return itsClockImp;
  }

  public api.TemperatureSensorImp makeTemperature()
  {
    return new test.TemperatureImp();
  }

  public api.BarometricPressureSensorImp makeBarometricPressure()
  {
    return new test.BarometricPressureImp();
  }
}

