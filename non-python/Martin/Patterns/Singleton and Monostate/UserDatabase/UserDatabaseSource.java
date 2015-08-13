public class UserDatabaseSource implements UserDatabase
{
	private static UserDatabase theInstance = new UserDatabaseSource();
	public static UserDatabase instance() 
	{
		return theInstance;
	}
	
	private UserDatabaseSource()
	{
	}
	
	public User readUser(String userName)
	{
		// Some Implementation
		return null;  // just to make it compile.S
	}
	
	public void writeUser(User user)
	{
		// Some Implementation
	}
}
