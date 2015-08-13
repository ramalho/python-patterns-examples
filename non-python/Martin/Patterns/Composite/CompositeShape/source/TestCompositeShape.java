import junit.framework.TestCase;
import junit.swingui.TestRunner;

public class TestCompositeShape extends TestCase
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"TestCompositeShape"});
  }

  public TestCompositeShape(String name)
  {
    super(name);
  }

  private int drawCount = 0;

  public void testNullComposite() throws Exception
  {
    CompositeShape s = new CompositeShape();
    s.draw();
    assertEquals(0, drawCount);
  }

  public void testCompositeWithOneShape() throws Exception
  {
    CompositeShape s = new CompositeShape();
    s.add(new TestShape());
    s.draw();
    assertEquals(1, drawCount);
  }

  public void testCompositeWithNShapes() throws Exception
  {
    CompositeShape s = new CompositeShape();
    for (int i = 0; i < 100; i++)
    {
      s.add(new TestShape());
    }
    s.draw();
    assertEquals(100, drawCount);
  }

  private class TestShape implements Shape
  {
    public void draw()
    {
      drawCount++;
    }
  }
}

