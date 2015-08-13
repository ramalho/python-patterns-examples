interface TurnstyleState
{
  void coin(Turnstyle t);
  void pass(Turnstyle t);
}

class LockedTurnstyleState implements TurnstyleState
{
  public void coin(Turnstyle t)
  {
    t.setUnlocked();
    t.unlock();
  }

  public void pass(Turnstyle t)
  {
    t.alarm();
  }
}

class UnlockedTurnstyleState implements TurnstyleState
{
  public void coin(Turnstyle t)
  {
    t.thankyou();
  }

  public void pass(Turnstyle t)
  {
    t.setLocked();
    t.lock();
  }
}