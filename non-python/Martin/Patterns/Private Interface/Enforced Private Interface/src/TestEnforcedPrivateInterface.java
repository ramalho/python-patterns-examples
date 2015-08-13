import junit.framework.*;
import junit.swingui.TestRunner;

public class TestEnforcedPrivateInterface extends TestCase
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"TestEnforcedPrivateInterface"});
  }

  public TestEnforcedPrivateInterface(String name)
  {
    super(name);
  }

  private PrivateMethodAccessor itsAccessor;
  public void setPrivateAccessor(PrivateMethodAccessor accessor)
  {
    itsAccessor = accessor;
  }

  public void testCallPrivateMethod() throws Exception
  {
    ClassWithPrivateMethod c = new ClassWithPrivateMethod();
    c.sendPrivateAccessor(this);
    itsAccessor.private_f();
  }
}
