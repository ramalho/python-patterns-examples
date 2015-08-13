package com.objectmentor.PPP.Patterns.State.turnstyle;

public class Turnstyle
{
  // States
  public static final int LOCKED = 0;
  public static final int UNLOCKED = 1;

  // Events
  public static final int COIN = 0;
  public static final int PASS = 1;

  /*private*/ int state = LOCKED;

  private TurnstyleController turnstyleController;

  public Turnstyle(TurnstyleController action)
  {
    turnstyleController = action;
  }

  public void event(int event)
  {
    switch (state)
    {
    case LOCKED:
      switch (event)
      {
      case COIN:
        state = UNLOCKED;
        turnstyleController.unlock();
        break;
      case PASS:
        turnstyleController.alarm();
        break;
      }
      break;
    case UNLOCKED:
      switch (event)
      {
      case COIN:
        turnstyleController.thankyou();
        break;
      case PASS:
        state = LOCKED;
        turnstyleController.lock();
        break;
      }
      break;
    }
  }
}
