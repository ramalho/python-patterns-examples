import junit.framework.TestCase;
import org.jdom.input.DOMBuilder;
import org.jdom.Document;
import org.jdom.output.XMLOutputter;

import java.io.ByteArrayInputStream;

public class PayrollTest extends TestCase implements PaycheckWriter
{
  private SalariedEmployee salariedEmployee;
  private Document itsActualDocument;

  public PayrollTest( String name )
  {
    super(name);
  }

  public static void main(String[] args)
  {
    junit.swingui.TestRunner.main(new String[] {"PayrollTest"});
  }

  public void setUp()  throws Exception
  {
    salariedEmployee = new SalariedEmployee(0, "Uncle Bob", 999999);
    DB.init();
  }

  public void tearDown()  throws Exception
  {
    DB.close();
  }


  public void testParseTwoAddEmpTransactions() throws Exception
  {
    String transactionDocument = "<Transactions>"+
                                    "<AddEmp id='0' name='Uncle Bob' salary='999999'/>"+
                                    "<AddEmp id='1' name='Young Bob' salary='666666'/>"+
                                 "</Transactions>";
    SalariedEmployee uncleBob = new SalariedEmployee(0, "Uncle Bob", 999999);
    SalariedEmployee youngBob = new SalariedEmployee(1, "Young Bob", 666666);

    TransactionParser.parseDocument(transactionDocument, this);
    SalariedEmployee ub = DB.retrieve(0);
    SalariedEmployee yb = DB.retrieve(1);
    DB.delete(ub.getId());
    DB.delete(yb.getId());
    assertEquals(uncleBob, ub);
    assertEquals(youngBob, yb);
  }

  public void write(Document doc)
  {
    itsActualDocument = doc;
  }

  public void testEndToEndPayday() throws Exception
  {
    String transactionDocument =
      "<Transactions>" +
        "<AddEmp id='0' name='Robert Martin' salary='3245'/>" +
        "<AddEmp id='6' name='Robert Koss' salary='4625'/>" +
        "<AddEmp id='18' name='Alan Francis' salary='1872'/>" +
        "<AddEmp id='13' name='Erik Meade' salary='2256'/>" +
        "<PayDay/>" +
      "</Transactions>";
    String expectedXml = "<PayDay>" +
                            "<paycheck><id>0</id><name>Robert Martin</name><grosspay>3245</grosspay></paycheck>" +
                            "<paycheck><id>6</id><name>Robert Koss</name><grosspay>4625</grosspay></paycheck>" +
                            "<paycheck><id>18</id><name>Alan Francis</name><grosspay>1872</grosspay></paycheck>" +
                            "<paycheck><id>13</id><name>Erik Meade</name><grosspay>2256</grosspay></paycheck>" +
                         "</PayDay>";
    DOMBuilder dom = new DOMBuilder();
    Document expectedDocument = dom.build(new ByteArrayInputStream(expectedXml.getBytes()));

    TransactionParser.parseDocument(transactionDocument, this);
    DB.delete(0);
    DB.delete(6);
    DB.delete(18);
    DB.delete(13);

    XMLOutputter out = new XMLOutputter();
    String expectedString = out.outputString(expectedDocument);
    String actualString = out.outputString(itsActualDocument);
    assertEquals(expectedString, actualString);
  }

}

