
public class SalariedEmployee
{
  private int itsPay = 0;

  public SalariedEmployee(int pay)
  {
    itsPay = pay;
  }

  public Paycheck pay()
  {
    return new Paycheck(itsPay);
  }
}
