import junit.framework.*;

public class TestUserDatabase extends TestCase
{
	public TestUserDatabase(String name)
	{
		super(name);
	}
	
	public void testIsSingleton()
	{
		UserDatabase udb = UserDatabaseSource.instance();
		assertNotNull(udb);
		User u = udb.readUser("x");
		assertNull(u);
		assertSame(udb, UserDatabaseSource.instance());
	}
}
