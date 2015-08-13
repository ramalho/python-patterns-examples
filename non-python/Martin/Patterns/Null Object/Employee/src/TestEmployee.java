
import junit.framework.TestCase;
import junit.swingui.TestRunner;

import java.util.Date;

public class TestEmployee extends TestCase
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"TestEmployee"});
  }

  public TestEmployee(String name)
  {
    super(name);
  }

  public void setUp() throws Exception
  {
  }

  public void tearDown() throws Exception
  {
  }

  public void testNull() throws Exception
  {
    Employee e = DB.getEmployee("Bob");
    if (e.isTimeToPay(new Date()))
      fail();
    assertEquals(Employee.NULL, e);
  }
}

