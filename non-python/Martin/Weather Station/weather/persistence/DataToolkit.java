package persistence;

import wmsdata.HiLoData;
import wmsdata.NoSuchDateException;
import java.util.Date;

public class DataToolkit implements wmsdata.DataToolkit
{
  final private String temperatureKey = "Temp";

  public HiLoData getTempHiLoData(Date aDate) throws NoSuchDateException
  {
    return new HiLoProxy(temperatureKey, aDate);
  }

  public HiLoData getTempHiLoData(Date aDate, double initialValue) 
  {
    return new HiLoProxy(temperatureKey, aDate, initialValue);
  }
}
