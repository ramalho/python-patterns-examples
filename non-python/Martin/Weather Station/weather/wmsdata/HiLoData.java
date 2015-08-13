package wmsdata;

public interface HiLoData 
{
  double getHighValue();
  double getLowValue();
  long getHighTime();
  long getLowTime();

  boolean currentReading(double current, long time);
  void newDay(double initial, long time);
}
