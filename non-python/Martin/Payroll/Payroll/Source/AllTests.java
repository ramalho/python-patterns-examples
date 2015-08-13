import junit.framework.TestSuite;
import junit.framework.Test;

public class AllTests
{
  public static void main( String[] args )
  {
    junit.swingui.TestRunner.main( new String[] {"AllTests"} );
  }

  public static Test suite()
  {
    TestSuite suite = new TestSuite();

    suite.addTest( new TestSuite( PayrollTest.class ) );

    return suite;
  }
}
