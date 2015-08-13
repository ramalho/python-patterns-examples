package wmsdataimp;

public class HiLoDataImp implements java.io.Serializable,
                                    wmsdata.HiLoData
{
  private double itsHighValue;
  private double itsLowValue;
  private long itsHighTime;
  private long itsLowTime;

  public HiLoDataImp(double initial, long time)
  {
    itsHighValue = itsLowValue = initial;
    itsHighTime = itsLowTime = time;
  }

  public double getHighValue()
  { return itsHighValue; }
  public double getLowValue()
  { return itsLowValue; }
  public long getHighTime()
  { return itsHighTime; }
  public long getLowTime()
  { return itsLowTime; }

  public boolean currentReading(double current, long time)
  {
    boolean rtnVal = false;

    if(current > itsHighValue)
    {
      itsHighTime = time;
      itsHighValue = current;
      rtnVal = true;
    }
    else if(current < itsLowValue)
    {
      itsLowTime = time;
      itsLowValue = current;
      rtnVal = true;
    }

    return rtnVal;
  }

  public void newDay(double initial, long time)
  {
    itsLowValue = itsHighValue = initial;
    itsHighTime = itsLowTime = time;
  }
}
