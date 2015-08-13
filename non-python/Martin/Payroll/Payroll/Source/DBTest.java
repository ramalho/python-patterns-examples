import junit.framework.*;
import junit.swingui.TestRunner;

public class DBTest extends TestCase
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"DBTest"});
  }

  public DBTest(String name)
  {
    super(name);
  }

  public void setUp() throws Exception
  {
    DB.init();
  }

  public void tearDown() throws Exception
  {
    DB.close();
  }

  public void testConnection() throws Exception
  {
    assert(!DB.con.isClosed());
  }

  public void testStoreRetrieveDeleteSalariedEmployee() throws Exception
  {
    int id = 6;
    SalariedEmployee original = new SalariedEmployee( id, "Young Bob", 12334 );
    assertEquals( 0, DB.getNumberOfEmployees() );
    DB.store( original );
    assertEquals( 1, DB.getNumberOfEmployees() );
    SalariedEmployee expected = DB.retrieve(id);
    assertEquals( expected, original );
    DB.delete(id);
    assertEquals( 0, DB.getNumberOfEmployees() );
  }
}
