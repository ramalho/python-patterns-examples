import junit.framework.*;
import junit.swingui.TestRunner;

public class TestThrowException extends TestCase
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"TestThrowException"});
  }

  public TestThrowException(String name)
  {
    super(name);
  }

  public void setUp() throws Exception
  {
  }

  public void tearDown() throws Exception
  {
  }

  public void testBase() throws Exception
  {
    Base b = new Base();
    b.f();
  }

  public void testDerived() throws Exception
  {
    Base b = new Derived();
    try
    {
      b.f();
      fail();
    }
    catch (Exception e)
    {
    }
  }
}