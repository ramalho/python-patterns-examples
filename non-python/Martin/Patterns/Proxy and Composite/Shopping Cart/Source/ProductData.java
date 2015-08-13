
public class ProductData
{
  public String name;
  public int price;

  public ProductData()
  {
  }

  public ProductData(String name, int price, String sku)
  {
    this.name = name;
    this.price = price;
    this.sku = sku;
  }

  public String sku;

  public boolean equals(Object o)
  {
    ProductData pd = (ProductData)o;
    return name.equals(pd.name) && sku.equals(pd.sku) && price==pd.price;
  }
  public String toString()
  {
    return ("ProductData("+sku+","+name+","+price+")");
  }
}
