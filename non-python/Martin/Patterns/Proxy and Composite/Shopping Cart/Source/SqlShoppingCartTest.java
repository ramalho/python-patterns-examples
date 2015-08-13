import junit.framework.*;
import java.sql.*;

public class SqlShoppingCartTest extends TestCase
{
    public static void main(String[] args)
    {
      junit.swingui.TestRunner.main(new String[] {"SqlShoppingCartTest"});
    }
	public SqlShoppingCartTest(String name)
	{
		super(name);
	}
	
	private Connection c;
	private Statement s;
	
	public void setUp() throws Exception
	{
		Class.forName("sun.jdbc.odbc.JdbcOdbcDriver"); // load driver
		c = DriverManager.getConnection("jdbc:odbc:PPP Shopping Cart");
		s = c.createStatement();
	}
	
	public void tearDown() throws Exception
	{
		s.executeUpdate("Delete from Customers where cusid = 0");
		c.close();
	}
	
	public void testReadWrite() throws Exception
	{
		s = c.createStatement();
		s.executeUpdate("Insert into Customers values (0,'Bob', '14619', 'amex')");
		ResultSet rs = s.executeQuery("Select * from Customers where cusid = 0");
		rs.next();
		assertEquals("Bob", rs.getString("name"));
		assertEquals("14619", rs.getString("address"));
		assertEquals("amex", rs.getString("billing information"));
		rs.close();
	}
}
