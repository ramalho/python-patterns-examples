
public class ClassWithPrivateMethod
{
  private void f()
  {
    System.out.println("hi");
  }

  public PrivateMethodAccessor getPrivateMethodAccessor()
  {
    return new PrivateMethodAccessor(){
      public void private_f()
      {
        f();
      }
    };
  }
}
