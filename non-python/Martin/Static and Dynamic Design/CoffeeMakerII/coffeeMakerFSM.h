#ifndef FSM_CoffeeMakerFSM_06_14_1999_08_11_54_H
#define FSM_CoffeeMakerFSM_06_14_1999_08_11_54_H
//----------------------------------------------
// coffeeMaker.h
// FSM:       CoffeeMakerFSM
// Context:   CoffeeMaker
// Version:   14 Jun 99 rcm
// Generated: Monday 06/14/1999 at 08:11:54 CDT
//
//----------------------------------------------


// Included header files

#include "coffeeMaker.h"
#include <stddef.h>

namespace com_cmindustries_coffeeMakerFSM
{

// Forward Declarations

class CoffeeMakerFSM;

//----------------------------------------------
// CoffeeMakerFSMState: The base state class
//----------------------------------------------
class CoffeeMakerFSMState
{
  public: 
    virtual const char* StateName() const = 0;
    virtual void Done( CoffeeMakerFSM& );
    virtual void Ready( CoffeeMakerFSM& );
    virtual void Complete( CoffeeMakerFSM& );
    virtual void Start( CoffeeMakerFSM& );
    virtual void NotReady( CoffeeMakerFSM& );
};

//----------------------------------------------
// State: Brewing
//----------------------------------------------
class CoffeeMakerFSMBrewingState : public CoffeeMakerFSMState
{
  public: 
    virtual const char* StateName() const
        { return "Brewing"; }
    virtual void NotReady( CoffeeMakerFSM& );
    virtual void Done( CoffeeMakerFSM& );
};

//----------------------------------------------
// State: Brewed
//----------------------------------------------
class CoffeeMakerFSMBrewedState : public CoffeeMakerFSMState
{
  public: 
    virtual const char* StateName() const
        { return "Brewed"; }
    virtual void Complete( CoffeeMakerFSM& );
};

//----------------------------------------------
// State: BrewingPaused
//----------------------------------------------
class CoffeeMakerFSMBrewingPausedState : public CoffeeMakerFSMState
{
  public: 
    virtual const char* StateName() const
        { return "BrewingPaused"; }
    virtual void Ready( CoffeeMakerFSM& );
};

//----------------------------------------------
// State: Idle
//----------------------------------------------
class CoffeeMakerFSMIdleState : public CoffeeMakerFSMState
{
  public: 
    virtual const char* StateName() const
        { return "Idle"; }
    virtual void Start( CoffeeMakerFSM& );
};

//----------------------------------------------
// CoffeeMakerFSM: The Finite State Machine class
//----------------------------------------------
class CoffeeMakerFSM: public CoffeeMaker
{
  public: 
    // Static State variables
    static CoffeeMakerFSMBrewingState Brewing;
    static CoffeeMakerFSMBrewedState Brewed;
    static CoffeeMakerFSMBrewingPausedState BrewingPaused;
    static CoffeeMakerFSMIdleState Idle;

    CoffeeMakerFSM(); // default Constructor

    // Event functions
    void Done() { itsState->Done( *this ); }
    void Ready() { itsState->Ready( *this ); }
    void Complete() { itsState->Complete( *this ); }
    void Start() { itsState->Start( *this ); }
    void NotReady() { itsState->NotReady( *this ); }

    // State Accessor functions
    void SetState( CoffeeMakerFSMState& theState ) { itsState = &theState; }
    CoffeeMakerFSMState& GetState() const { return *itsState; }

    const char* GetCurrentStateName() const { return itsState->StateName(); }
    const char* GetVersion() const;

  private:
    CoffeeMakerFSMState* itsState;
};

}  // end namespace com_cmindustries_coffeeMakerFSM

#endif /* FSM_CoffeeMakerFSM_06_14_1999_08_11_54_H */
