import junit.framework.TestCase;
import junit.swingui.TestRunner;

public class TestActiveObjectEngine extends TestCase
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"TestActiveObjectEngine"});
  }

  public TestActiveObjectEngine(String name)
  {
    super(name);
  }

  private boolean firstCommandExecuted = false;

  public void testOneCommand() throws Exception
  {
    ActiveObjectEngine e = new ActiveObjectEngine();
    e.addCommand(
      new Command()
      {
        public void execute()
        {
          firstCommandExecuted = true;
        }
      }
    );
    e.run();
    assert("Command not executed", firstCommandExecuted);
  }

  private boolean secondCommandExecuted = false;
  public void testTwoCommands() throws Exception
  {
    ActiveObjectEngine e = new ActiveObjectEngine();
    e.addCommand(
      new Command()
      {
        public void execute()
        {
          firstCommandExecuted = true;
        }
      }
    );
    e.addCommand(
      new Command()
      {
        public void execute()
        {
          secondCommandExecuted = true;
        }
      }
    );
    e.run();
    assert("Commands not executed", firstCommandExecuted && secondCommandExecuted);
  }
}
