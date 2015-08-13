import junit.framework.*;
import junit.swingui.TestRunner;

public class TestPrivateInterface extends TestCase
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"TestPrivateInterface"});
  }

  public TestPrivateInterface(String name)
  {
    super(name);
  }

  public void testInvokeF() throws Exception
  {
    ClassWithPrivateMethod c = new ClassWithPrivateMethod();
    c.getPrivateMethodAccessor().private_f();
  }
}