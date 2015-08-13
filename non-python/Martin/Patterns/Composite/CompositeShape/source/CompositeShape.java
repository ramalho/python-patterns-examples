import java.util.Vector;

public class CompositeShape implements Shape
{
  private Vector itsShapes = new Vector();
  public void add(Shape s)
  {
    itsShapes.add(s);
  }

  public void draw()
  {
    for (int i = 0; i < itsShapes.size(); i++)
    {
      Shape shape = (Shape) itsShapes.elementAt(i);
      shape.draw();
    }
  }
}
