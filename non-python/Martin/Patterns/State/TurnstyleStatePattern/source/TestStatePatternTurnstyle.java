import junit.framework.*;
import junit.swingui.TestRunner;

public class TestStatePatternTurnstyle extends TestCase
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"TestStatePatternTurnstyle"});
  }

  public TestStatePatternTurnstyle(String name)
  {
    super(name);
  }

  private Turnstyle t;
  private boolean lockCalled = false;
  private boolean unlockCalled = false;
  private boolean thankyouCalled = false;
  private boolean alarmCalled = false;


  public void setUp()
  {
    TurnstyleController controllerSpoof = new TurnstyleController()
    {
      public void lock() {lockCalled = true;}
      public void unlock() {unlockCalled = true;}
      public void thankyou() {thankyouCalled = true;}
      public void alarm() {alarmCalled = true;}
    };

    t = new Turnstyle(controllerSpoof);
  }

  public void testInitialConditions()
  {
    assert(t.isLocked());
  }

  public void testCoinInLockedState()
  {
    t.setLocked();
    t.coin();
    assert(t.isUnlocked());
    assert(unlockCalled);
  }

  public void testCoinInUnlockedState()
  {
    t.setUnlocked();
    t.coin();
    assert(t.isUnlocked());
    assert(thankyouCalled);
  }

  public void testPassInLockedState()
  {
    t.setLocked();
    t.pass();
    assert(t.isLocked());
    assert(alarmCalled);
  }

  public void testPassInUnlockedState()
  {
    t.setUnlocked();
    t.pass();
    assert(t.isLocked());
    assert(lockCalled);
  }
}
