package test;

class TemperatureImp implements api.TemperatureSensorImp
{
  private static int value = 0;

  public double read()
  {
    return ++value;
  }
}
