
import junit.framework.*;
import junit.swingui.TestRunner;

public class AllTests
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"AllTests"});
  }

  public static Test suite()
  {
    TestSuite suite = new TestSuite("AllTests");
    suite.addTest(new TestSuite(TestShoppingCart.class ) );
    suite.addTest(new TestSuite(DBTest.class));
    suite.addTest(new TestSuite(ProxyTest.class));
    return suite;
  }
}
