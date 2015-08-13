import junit.framework.*;
import junit.swingui.TestRunner;

public class TestStateTableTurnstyle extends TestCase
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"TestStateTableTurnstyle"});
  }

  public TestStateTableTurnstyle(String name)
  {
    super(name);
  }

  private boolean lockCalled = false;
  private boolean unlockCalled = false;
  private boolean thankyouCalled = false;
  private boolean alarmCalled = false;

  private Turnstyle t = null;

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

  public void testCoin() throws Exception
  {
    assertEquals(Turnstyle.LOCKED, t.state);
  }

  public void testCoinInLockedState()
  {
    t.state = Turnstyle.LOCKED;
    t.event(Turnstyle.COIN);
    assertEquals(Turnstyle.UNLOCKED, t.state);
    assert(unlockCalled);
  }

  public void testCoinInUnlockedState()
  {
    t.state = Turnstyle.UNLOCKED;
    t.event(Turnstyle.COIN);
    assertEquals(Turnstyle.UNLOCKED, t.state);
    assert(thankyouCalled);
  }

  public void testPassInLockedState()
  {
    t.state = Turnstyle.LOCKED;
    t.event(Turnstyle.PASS);
    assertEquals(Turnstyle.LOCKED, t.state);
    assert(alarmCalled);
  }

  public void testPassInUnlockedState()
  {
    t.state = Turnstyle.UNLOCKED;
    t.event(Turnstyle.PASS);
    assertEquals(Turnstyle.LOCKED, t.state);
    assert(lockCalled);
  }
}