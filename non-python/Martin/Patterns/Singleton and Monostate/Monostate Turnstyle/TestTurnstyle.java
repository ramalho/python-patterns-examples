import junit.framework.*;

public class TestTurnstyle extends TestCase
{
	public TestTurnstyle(String name)
	{
		super(name);
	}

	public void setUp()
	{
		Turnstyle t = new Turnstyle();
		t.reset();
	}

	public void testInit()
	{
		Turnstyle t = new Turnstyle();
		assert(t.locked());
		assert(!t.alarm());
	}

	public void testCoin()
	{
		Turnstyle t = new Turnstyle();
		t.coin();
		Turnstyle t1 = new Turnstyle();
		assert(!t1.locked());
		assert(!t1.alarm());
		assertEquals(1, t1.coins());
	}

	public void testCoinAndPass()
	{
		Turnstyle t = new Turnstyle();
		t.coin();
		t.pass();

		Turnstyle t1 = new Turnstyle();
		assert(t1.locked());
		assert(!t1.alarm());
		assertEquals("coins", 1, t1.coins());
	}

	public void testTwoCoins()
	{
		Turnstyle t = new Turnstyle();
		t.coin();
		t.coin();

		Turnstyle t1 = new Turnstyle();
		assert("unlocked", !t1.locked());
		assertEquals("coins",1, t1.coins());
		assertEquals("refunds", 1, t1.refunds());
		assert(!t1.alarm());
	}

	public void testPass()
	{
		Turnstyle t = new Turnstyle();
		t.pass();
		Turnstyle t1 = new Turnstyle();
		assert("alarm", t1.alarm());
		assert("locked", t1.locked());
	}

	public void testCancelAlarm()
	{
		Turnstyle t = new Turnstyle();
		t.pass();
		t.coin();
		Turnstyle t1 = new Turnstyle();
		assert("alarm", !t1.alarm());
		assert("locked", !t1.locked());
		assertEquals("coin", 1, t1.coins());
		assertEquals("refund", 0, t1.refunds());
	}

	public void testTwoOperations()
	{
		Turnstyle t = new Turnstyle();
		t.coin();
		t.pass();
		t.coin();
		assert("unlocked", !t.locked());
		assertEquals("coins", 2, t.coins());
		t.pass();
		assert("locked", t.locked());
	}
}
