
import junit.framework.*;
import junit.swingui.TestRunner;

import java.util.Vector;

public class DBTest extends TestCase
{
  public static void main(String[] args)
  {
    TestRunner.main(new String[]{"DBTest"});
  }

  public DBTest(String name)
  {
    super(name);
  }

  public void setUp() throws Exception
  {
    DB.init();
    DB.clear();
  }

  public void tearDown() throws Exception
  {
    DB.close();
  }

  public void testStoreProduct() throws Exception
  {
    ProductData storedProduct = new ProductData("MyProduct", 1234, "999");
    DB.store(storedProduct);
    ProductData retrievedProduct = DB.getProductData("999");
    assertEquals(storedProduct, retrievedProduct);
  }

  public void testNoProduct() throws Exception
  {
    ProductData none = DB.getProductData("none");
    assertEquals(null, none);
  }

  public void testStoreItem() throws Exception
  {
    ItemData storedItem = new ItemData(1, 3, "sku");
    DB.store(storedItem);
    ItemData[] retrievedItems = DB.getItemsForOrder(1);
    assertEquals(1, retrievedItems.length);
    assertEquals(storedItem, retrievedItems[0]);
  }

  public void testNoItems() throws Exception
  {
    ItemData[] id = DB.getItemsForOrder(42);
    assertEquals(0, id.length);
  }

  public void testOrderKeyGeneration() throws Exception
  {
    OrderData o1 = DB.newOrder("Bob");
    OrderData o2 = DB.newOrder("Bill");
    int firstOrderId = o1.orderId;
    int secondOrderId = o2.orderId;
    assertEquals(firstOrderId+1, secondOrderId);
  }

  public void testNoOrder() throws Exception
  {
    OrderData none = DB.getOrderData(0);
    assertEquals(null, none);
  }
}
