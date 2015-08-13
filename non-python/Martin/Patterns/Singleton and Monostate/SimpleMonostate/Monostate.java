public class Monostate
{
	private static int itsX = 0;
	public Monostate() {}
	
	public void setX(int x)
	{
		itsX = x;
	}
	
	public int getX()
	{
		return itsX;
	}
}
