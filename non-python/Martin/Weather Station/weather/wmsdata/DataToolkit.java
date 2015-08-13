package wmsdata;

import java.util.Date;

public interface DataToolkit
{
  HiLoData getTempHiLoData(Date aDate) throws NoSuchDateException;
  HiLoData getTempHiLoData(Date aDate, double initialValue); 
}
