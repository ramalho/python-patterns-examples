import junit.framework.*;
public class TestShoppingCart extends TestCase
{
  public static void main(String[] args)
  {
    junit.swingui.TestRunner.main(new String[] {"TestShoppingCart"});
  }

  public TestShoppingCart(String name)
  {
    super(name);
  }

  public void testOrderPrice() throws Exception
  {
    OrderImp o = new OrderImp("Bob");
    Product toothpaste = new ProductImp("sku1", "Toothpaste", 129);
    o.addItem(toothpaste, 1);
    assertEquals(129, o.total());
    Product mouthwash = new ProductImp("sku2", "Mouthwash", 342);
    o.addItem(mouthwash, 2);
    assertEquals(813, o.total());
  }
}
