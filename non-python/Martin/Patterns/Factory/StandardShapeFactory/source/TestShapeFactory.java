import junit.framework.TestCase;
import junit.swingui.TestRunner;

public class TestShapeFactory extends TestCase
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"TestShapeFactory"});
  }

  public TestShapeFactory(String name)
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
    Shape s = factory.makeCircle();
    assertEquals("Circle", s.getShapeType());
  }

  public void testCreateSquare() throws Exception
  {
    Shape s = factory.makeSquare();
    assertEquals("Square", s.getShapeType());
  }
}