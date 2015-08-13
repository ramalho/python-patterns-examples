import junit.framework.*;

public class TestMonostate extends TestCase
{
	public TestMonostate(String name)
	{
		super(name);
	}
	
	public void testInstance()
	{
		Monostate m = new Monostate();
		for (int x = 0; x<10; x++)
		{
			m.setX(x);
			assertEquals(x, m.getX());
		}
	}
	
	public void testInstancesBehaveAsOne()
	{
		Monostate m1 = new Monostate();
		Monostate m2 = new Monostate();

		for (int x = 0; x<10; x++)
		{
			m1.setX(x);
			assertEquals(x, m2.getX());
		}
	}
}
