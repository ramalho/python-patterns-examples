
public class ClassWithPrivateMethod
{
  private void f()
  {
    System.out.println("hi");
  }

  public void sendPrivateAccessor(TestEnforcedPrivateInterface allowedClass)
  {
    allowedClass.setPrivateAccessor(
      new PrivateMethodAccessor()
      {
        public void private_f()
        {
          f();
        }
      }
    );
  }
}
