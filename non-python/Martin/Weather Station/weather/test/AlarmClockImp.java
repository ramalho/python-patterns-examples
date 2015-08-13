package test;

import api.ClockListener;

public class AlarmClockImp implements api.AlarmClockImp
{
  public void register(ClockListener aListener)
  {
    new Timer(10, aListener).start();
  }
}
