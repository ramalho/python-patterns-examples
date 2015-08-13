
public class Turnstyle
{
  private static TurnstyleState lockedState = new LockedTurnstyleState();
  private static TurnstyleState unlockedState = new UnlockedTurnstyleState();

  private TurnstyleController turnstyleController;
  private TurnstyleState state = lockedState;

  public Turnstyle(TurnstyleController action)
  {
    turnstyleController = action;
  }

  public void coin()
  {
    state.coin(this);
  }

  public void pass()
  {
    state.pass(this);
  }

  public void setLocked()
  {
    state = lockedState;
  }

  public void setUnlocked()
  {
    state = unlockedState;
  }

  public boolean isLocked()
  {
    return state == lockedState;
  }

  public boolean isUnlocked()
  {
    return state == unlockedState;
  }

  void thankyou()
  {
    turnstyleController.thankyou();
  }

  void alarm()
  {
    turnstyleController.alarm();
  }

  void lock()
  {
    turnstyleController.lock();
  }

  void unlock()
  {
    turnstyleController.unlock();
  }
}
