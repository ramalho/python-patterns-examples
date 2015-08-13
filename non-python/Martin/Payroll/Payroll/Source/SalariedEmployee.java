
public class SalariedEmployee
{
  private int itsSalary = 0;
  private int itsId = 0;
  private String itsName;

  public SalariedEmployee(int id, String name, int pay)
  {
    itsSalary = pay;
    itsName = name;
    itsId = id;
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

  public boolean equals(Object o)
  {
    SalariedEmployee otherEmp = (SalariedEmployee)o;
    return (otherEmp.getId() == itsId &&
            otherEmp.getName().equals(itsName) &&
            otherEmp.getSalary() == itsSalary);
  }
}
