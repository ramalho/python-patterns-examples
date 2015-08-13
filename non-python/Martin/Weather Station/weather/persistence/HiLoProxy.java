
package persistence;

import java.util.Date;
import java.text.SimpleDateFormat;
import api.PersistentImp;
import wmsdataimp.HiLoDataImp;

public class HiLoProxy implements wmsdata.HiLoData
{
  private HiLoDataImp itsHiLoData;

  private PersistentImp itsPI;

  private String itsType;
  private String itsStorageKey;

  public HiLoProxy(String type, Date aDate) 
             throws wmsdata.NoSuchDateException
  {
    itsType = type;
    itsStorageKey = calculateStorageKey(new Date());

    itsPI = api.Scope.stationToolkit.getPersistentImp();

    try
    {
      itsHiLoData = (HiLoDataImp)itsPI.retrieveObject(itsStorageKey);
    }
    catch(api.RetrieveException re)
    {
      throw new wmsdata.NoSuchDateException(itsStorageKey);
    }
  }

  public HiLoProxy(String type, 
                   Date aDate, 
                   double initialValue) 
  {
    itsType = type;
    itsStorageKey = calculateStorageKey(aDate);

    itsPI = api.Scope.stationToolkit.getPersistentImp();

    try
    {
      itsHiLoData = (HiLoDataImp)itsPI.retrieveObject(itsStorageKey);
      itsHiLoData.currentReading(initialValue, aDate.getTime());
    }
    catch(api.RetrieveException re)
    {
      System.out.println("Could not retrieve");
      itsHiLoData = new HiLoDataImp(initialValue, aDate.getTime());
      store();
      System.exit(1);
    }
  }

  private String calculateStorageKey(Date theDate)
  {
    SimpleDateFormat dateFormat = new SimpleDateFormat("MMddyyyy");

    return (itsType + 
            "HiLo" + 
            dateFormat.format(theDate));
  }

  public boolean currentReading(double value, long time)
  {
    boolean rtnValue = itsHiLoData.currentReading(value, time);
    if(rtnValue == true)
    {
      store();
    }

    return rtnValue;
  }

  private void store()
  {
    try
    {
      itsPI.store(itsStorageKey, itsHiLoData);
    }
    catch(api.StoreException se)
    {
      // log the error somehow
    }
  }

  public void newDay(double initialValue, long time)
  {
    store();
    itsHiLoData.newDay(initialValue, time);
    itsStorageKey = calculateStorageKey(new Date(time));
    store();
  }

  public double getHighValue()
  { return itsHiLoData.getHighValue(); }
  public double getLowValue()
  { return itsHiLoData.getLowValue(); }
  public long getHighTime()
  { return itsHiLoData.getHighTime(); }
  public long getLowTime()
  { return itsHiLoData.getLowTime(); }
}
