import junit.framework.TestCase;

public class PayrollTest extends TestCase
{
  public PayrollTest( String name )
  {
    super(name);
  }

  public static void main(String[] args)
  {
    junit.swingui.TestRunner.main(new String[] {"PayrollTest"});
  }

  public void testPaySalariedEmployee()
  {
    SalariedEmployee salariedEmployee = new SalariedEmployee(123456);
    Paycheck paycheck = salariedEmployee.pay();
    assertEquals(123456, paycheck.grossPay());
  }
}

