import org.jdom.input.DOMBuilder;
import org.jdom.*;
import org.jdom.JDOMException;

import java.io.InputStream;
import java.io.ByteArrayInputStream;
import java.util.List;
import java.util.Iterator;

public class TransactionParser
{
  public static void parseDocument(String transactionDocument, PaycheckWriter writer) throws Exception
  {
    InputStream stream = new ByteArrayInputStream(transactionDocument.getBytes());
    DOMBuilder builder = new DOMBuilder();

    Document d = builder.build(stream);
    Element root = d.getRootElement();
    List l = root.getChildren();
    for (Iterator iterator = l.iterator(); iterator.hasNext();)
    {
      Element e = (Element) iterator.next();
      if (e.getName().equals("AddEmp"))
        addEmployee(e);
      else if (e.getName().equals("PayDay"))
        payDay(writer);
    }
  }

  private static void addEmployee(Element e) throws Exception
  {
    String id = e.getAttributeValue("id");
    String name = e.getAttributeValue("name");
    String salary = e.getAttributeValue("salary");
    DB.store(new SalariedEmployee(Integer.parseInt(id), name, Integer.parseInt(salary)));
  }

  private static void payDay(PaycheckWriter writer) throws Exception
  {
    List allEmployees = DB.getAllEmployees();
    Element root = new Element("PayDay");
    Document payday = new Document(root, new DocType("PayDay"));

    for (Iterator iterator = allEmployees.iterator(); iterator.hasNext();)
    {
      SalariedEmployee e = (SalariedEmployee) iterator.next();

      Element paycheckElement = new Element("paycheck");
      paycheckElement.addContent(new Element("id").addContent(e.getId()+""));
      paycheckElement.addContent(new Element("name").addContent(e.getName()));
      paycheckElement.addContent(new Element("grosspay").addContent(e.getSalary() + ""));
      root.addContent(paycheckElement);
    }
    writer.write(payday);
  }
}
