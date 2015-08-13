import junit.framework.*;
import junit.swingui.TestRunner;

public class ActiveObjectTestSuite
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"ActiveObjectTestSuite"});
  }

  public static Test suite()
  {
    TestSuite suite = new TestSuite("ActiveObjectTestSuite");
    suite.addTest(new TestSuite(TestActiveObjectEngine.class));
    suite.addTest(new TestSuite(TestSleepCommand.class));
    return suite;
  }
}