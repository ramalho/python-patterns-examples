
public class AddEmployeeTransaction
{
  private int itsId;
  private String itsName;
  private int itsSalary;
  public AddEmployeeTransaction(int id, String name, int salary)
  {
    itsId = id;
    itsName = name;
    itsSalary = salary;
  }
  public int getId()
  {
    return itsId;
  }

  public String getName()
  {
    return itsName;
  }

  public int getSalary()
  {
    return itsSalary;
  }
}
