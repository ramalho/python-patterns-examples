import junit.framework.*;
import junit.swingui.TestRunner;

public class TestDynamicShapeFactory extends TestCase
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"TestDynamicShapeFactory"});
  }

  public TestDynamicShapeFactory(String name)
  {
    super(name);
  }

  private ShapeFactory factory;
  public void setUp() throws Exception
  {
    factory = new ShapeFactoryImplementation();
  }

  public void tearDown() throws Exception
  {
  }

  public void testCreateCircle() throws Exception
  {
    Shape s = factory.make("Circle");
    assert(s instanceof Circle);
  }

  public void testCreateSquare() throws Exception
  {
    Shape s = factory.make("Square");
    assert(s instanceof Square);
  }

  public void testInvalidShape() throws Exception
  {
    try
    {
      Shape s = factory.make("Triangle");
      fail("Triangle not a valid type");
    }
    catch(Exception e)
    {
    }
  }
}
