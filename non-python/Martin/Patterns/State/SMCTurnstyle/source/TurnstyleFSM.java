
public class TurnstyleFSM  extends Turnstyle
{
  private TurnstyleController controller;
  public TurnstyleFSM(TurnstyleController controller)
  {
    this.controller = controller;
  }

  public void lock()
  {
    controller.lock();
  }

  public void unlock()
  {
    controller.unlock();
  }

  public void thankyou()
  {
    controller.thankyou();
  }

  public void alarm()
  {
    controller.alarm();
  }
}
