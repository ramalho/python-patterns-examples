public class DoubleBubbleSorter implements SortHandle
{
  private double[] array = null;

  public void swap(int index)
  {
    double temp = array[index];
    array[index] = array[index+1];
    array[index+1] = temp;
  }

  public int length()
  {
    return array.length;
  }

  public void setArray(Object array)
  {
    this.array = (double[])array;
  }

  public boolean outOfOrder(int index)
  {
    return (array[index] > array[index+1]);
  }
}