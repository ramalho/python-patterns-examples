import junit.framework.TestCase;

public class TransactionParserTest  extends TestCase
{
  public TransactionParserTest( String name )
  {
    super( name );
  }

  public void testAddEmp()
  {
    String addEmp = "<AddEmp id='0' name='Uncle Bob' salary='999999'/>";
    SalariedEmployee expectedEmployee = new SalariedEmployee(0, "Uncle Bob", 999999);
    AddEmployeeTransaction t = TransactionParser.parse(addEmp);
    assertEquals( 0, t.getId() );
    assertEquals( "Uncle Bob", t.getName() );
    assertEquals( 999999, t.getSalary() );
  }
}
