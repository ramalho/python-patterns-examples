import junit.framework.TestCase;

public class TestBubbleSort extends TestCase
{
  public static void main(String[] args)
  {
    junit.swingui.TestRunner.main(args);
  }
  public TestBubbleSort(String name)
  {
    super(name);
  }

  private QuickBubbleSorter sorter = null;
  protected void setUp()
  {
    sorter = new QuickBubbleSorter(new IntSortHandle());
  }

  public void testEmptyIntArray()
  {
    int[] array = new int[0];
    int operations = sorter.sort(array);
    assertEquals(0, operations);
  }

  public void testIntArrayWithOneElement()
  {
    int[] array = {0};
    int operations = sorter.sort(array);
    assertEquals(0, operations);
    assertEquals(0, array[0]);
    assertEquals(1, array.length);
  }

  public void testIntArrayWithTwoInOrderElements()
  {
    int[] array = {0,1};
    int operations = sorter.sort(array);
    assertEquals("operations",1, operations);
    assertEquals(0, array[0]);
    assertEquals(1, array[1]);
    assertEquals(2, array.length);
  }

  public void testIntArrayWithTwoOutOfOrderElements()
  {
    int[] array = {1,0};
    int operations = sorter.sort(array);
    assertEquals("operations",1, operations);
    assertEquals("array[0]", 0, array[0]);
    assertEquals("array[1]", 1, array[1]);
    assertEquals(2, array.length);
  }

  public void testIntArrayWithThreeOutOfOrderElements()
  {
    int[] array = {3,2,1};
    int operations = sorter.sort(array);
    assertEquals("operations", 3, operations);
    assertEquals("array[0]", 1, array[0]);
    assertEquals("array[1]", 2, array[1]);
    assertEquals("array[2]", 3, array[2]);
    assertEquals(3, array.length);
  }

  public void testIntArrayWithTenOutOfOrderElements()
  {
    int[] array = {9,8,7,6,5,4,3,2,1,0};
    int operations = sorter.sort(array);
    assertEquals("operations", 45, operations);
    for (int i=0; i<10; i++)
      assertEquals("array["+i+"]", i, array[i]);
  }

  public void testIntArrayWithTenInOrderElements()
  {
    int[] array = {0,1,2,3,4,5,6,7,8,9};
    int operations = sorter.sort(array);
    assertEquals("operations", 9, operations);
    for (int i=0; i<10; i++)
      assertEquals("array["+i+"]", i, array[i]);
  }

  public void testIntArrayWithTenOddOrderElements()
  {
    int[] array = {0,1,2,3,4,5,6,7,9,8};
    int operations = sorter.sort(array);
    assertEquals("operations", 17, operations);
    for (int i=0; i<10; i++)
      assertEquals("array["+i+"]", i, array[i]);
  }

  public void testDoubleArrayWithTenOutOfOrderElements()
  {
    double[] array = {9,8,7,6,5,4,3,2,1,0};
    int operations = (new BubbleSorter(new DoubleBubbleSorter())).sort(array);
    assertEquals("operations", 45, operations);
    for (int i=0; i<10; i++)
      assertEquals("array["+i+"]", i, array[i], .001);
  }
}