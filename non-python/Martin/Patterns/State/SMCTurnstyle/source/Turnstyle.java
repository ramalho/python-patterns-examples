//----------------------------------------------
//
// FSM:       Turnstyle
// Context:   TurnstyleActions
// Exception: FSMError
// Version:   
// Generated: Thursday 09/06/2001 at 12:23:59 CDT
//
//----------------------------------------------


//----------------------------------------------
//
// class Turnstyle
//    This is the Finite State Machine class
//
public class Turnstyle extends TurnstyleActions
{
  private State itsState;
  private static String itsVersion = "";

  // instance variables for each state
  private static Locked itsLockedState;
  private static Unlocked itsUnlockedState;

  // constructor
  public Turnstyle()
  {
    itsLockedState = new Locked();
    itsUnlockedState = new Unlocked();

    itsState = itsLockedState;

    // Entry functions for: Locked
  }

  // accessor functions

  public String getVersion()
  {
    return itsVersion;
  }

  public String getCurrentStateName()
  {
    return itsState.stateName();
  }

  // event functions - forward to the current State

  public void pass() throws FSMError
  {
    itsState.pass();
  }

  public void coin() throws FSMError
  {
    itsState.coin();
  }

  //--------------------------------------------
  //
  // private class State
  //    This is the base State class
  //
  private abstract class State
  {
    public abstract String stateName();

    // default event functions

    public void pass() throws FSMError
    {
      throw new FSMError( "pass", itsState.stateName());
    }

    public void coin() throws FSMError
    {
      throw new FSMError( "coin", itsState.stateName());
    }

  }

  //--------------------------------------------
  //
  // class Locked
  //    handles the Locked State and its events
  //
  private class Locked extends State 
  {
    public String stateName() 
      { return "Locked"; }

    //
    // responds to coin event
    //
    public void coin() 
    {
      unlock();

      // change the state
      itsState = itsUnlockedState;
    }

    //
    // responds to pass event
    //
    public void pass() 
    {
      alarm();

      // change the state
      itsState = itsLockedState;
    }
  }

  //--------------------------------------------
  //
  // class Unlocked
  //    handles the Unlocked State and its events
  //
  private class Unlocked extends State 
  {
    public String stateName() 
      { return "Unlocked"; }

    //
    // responds to pass event
    //
    public void pass() 
    {
      lock();

      // change the state
      itsState = itsLockedState;
    }

    //
    // responds to coin event
    //
    public void coin() 
    {
      thankyou();

      // change the state
      itsState = itsUnlockedState;
    }
  }

}
