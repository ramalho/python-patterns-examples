
public class ItemData
{
  public int orderId;
  public int qty;
  public String sku = "junk";

  public ItemData()
  {
  }

  public ItemData(int orderId, int qty, String sku)
  {
    this.orderId = orderId;
    this.qty = qty;
    this.sku = sku;
  }

  public boolean equals(Object o)
  {
    ItemData id = (ItemData)o;
    return orderId == id.orderId &&
           qty == id.qty &&
           sku.equals(id.sku);
  }
}
