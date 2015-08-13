public class Singleton
{
	private static Singleton theInstance = null;
	private Singleton() {}
	
	public static Singleton Instance()
	{
		if (theInstance == null)
			theInstance = new Singleton();
		return theInstance;	
	}
}
