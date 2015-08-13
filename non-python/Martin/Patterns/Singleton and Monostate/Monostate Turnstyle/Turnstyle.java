public class Turnstyle
{
	private static boolean isLocked;
	private static boolean isAlarming;
	private static int itsCoins;
	private static int itsRefunds;
	protected final static Turnstyle LOCKED = new Locked();
	protected final static Turnstyle UNLOCKED = new Unlocked();
	protected static Turnstyle itsState = LOCKED;

	public void reset()
	{
		lock(true);
		alarm(false);
		itsCoins = 0;
		itsRefunds = 0;
		itsState = LOCKED;
	}

	public boolean locked()
	{
		return isLocked;
	}

	public boolean alarm()
	{
		return isAlarming;
	}

	public void coin()
	{
		itsState.coin();
	}

	public void pass()
	{
		itsState.pass();
	}

	protected void lock(boolean shouldLock)
	{
		isLocked = shouldLock;
	}

	protected void alarm(boolean shouldAlarm)
	{
		isAlarming = shouldAlarm;
	}

	public int coins()
	{
		return itsCoins;
	}

	public int refunds()
	{
		return itsRefunds;
	}

	public void deposit()
	{
		itsCoins++;
	}

	public void refund()
	{
		itsRefunds++;
	}
}

  class Locked extends Turnstyle
{
	public void coin()
	{
		itsState = UNLOCKED;
		lock(false);
		alarm(false);
		deposit();
	}

	public void pass()
	{
		alarm(true);
	}
}

class Unlocked extends Turnstyle
{
	public void coin()
	{
		refund();
	}

	public void pass()
	{
		lock(true);
		itsState = LOCKED;
	}
}


