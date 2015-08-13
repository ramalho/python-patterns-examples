import java.sql.*;
import java.util.List;
import java.util.LinkedList;

public class DB
{
  static Connection con;

  public static void init() throws SQLException, ClassNotFoundException
  {
    Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
    con = DriverManager.getConnection("jdbc:odbc:PayrollDB","","");
  }

  public static int getNumberOfEmployees() throws SQLException
  {
    Statement s = con.createStatement();
    ResultSet rs = s.executeQuery("SELECT count(*) FROM SalariedEmployee");
    rs.next();
    int count = rs.getInt(1);
    rs.close();
    s.close();

    return count;
  }
  public static void store(SalariedEmployee employee) throws SQLException
  {
    PreparedStatement s = con.prepareStatement("INSERT INTO SalariedEmployee VALUES ( ?, ?, ?)");
    s.setInt(1, employee.getId());
    s.setString(2, employee.getName());
    s.setInt(3, employee.getSalary());
    s.executeUpdate();
    s.close();
  }

  public static List getAllEmployees() throws Exception
  {
    List employees = new LinkedList();
    Statement s = con.createStatement();
    ResultSet rs = s.executeQuery("SELECT id FROM SalariedEmployee");
    while (rs.next())
    {
      employees.add(retrieve(rs.getInt(1)));
    }
    rs.close();
    s.close();
    return employees;
  }

  public static SalariedEmployee retrieve(int id) throws Exception
  {
    SalariedEmployee emp = null;
    Statement s = con.createStatement();
    ResultSet rs = s.executeQuery("SELECT * FROM SalariedEmployee WHERE id = " + id);
    rs.next();
    emp = new SalariedEmployee(rs.getInt("id"), rs.getString("name"), rs.getInt("salary"));
    rs.close();
    s.close();
    return emp;
  }

  public static void close() throws SQLException
  {
    con.close();
  }

  public static void delete(int id) throws SQLException
  {
    Statement s = con.createStatement();
    s.execute("DELETE FROM SalariedEmployee WHERE id = " + id);
    s.close();
  }
}