//----------------------------------------------
// coffeeMaker.cpp
// FSM:       CoffeeMakerFSM
// Context:   CoffeeMaker
// Version:   14 Jun 99 rcm
// Generated: Monday 06/14/1999 at 08:11:54 CDT
//
//----------------------------------------------


static char _versID[]  = "14 Jun 99 rcm";

#include "coffeeMakerFSM.h"

namespace com_cmindustries_coffeeMakerFSM
{

//----------------------------------------------
// Definitions of static state objects
//----------------------------------------------
CoffeeMakerFSMBrewingState CoffeeMakerFSM::Brewing;
CoffeeMakerFSMBrewedState CoffeeMakerFSM::Brewed;
CoffeeMakerFSMBrewingPausedState CoffeeMakerFSM::BrewingPaused;
CoffeeMakerFSMIdleState CoffeeMakerFSM::Idle;

//----------------------------------------------
// Default Event Functions
//----------------------------------------------

void CoffeeMakerFSMState::Done(CoffeeMakerFSM& s)
  { s.FSMError("Done", s.GetState().StateName()); }

void CoffeeMakerFSMState::Ready(CoffeeMakerFSM& s)
  { s.FSMError("Ready", s.GetState().StateName()); }

void CoffeeMakerFSMState::Complete(CoffeeMakerFSM& s)
  { s.FSMError("Complete", s.GetState().StateName()); }

void CoffeeMakerFSMState::Start(CoffeeMakerFSM& s)
  { s.FSMError("Start", s.GetState().StateName()); }

void CoffeeMakerFSMState::NotReady(CoffeeMakerFSM& s)
  { s.FSMError("NotReady", s.GetState().StateName()); }

//----------------------------------------------
// The States and their Transitions
//----------------------------------------------

//----------------------------------------------
// Brewing Actions and Transitions
//----------------------------------------------

// Starting State: Brewing
// Event:          NotReady
//
void CoffeeMakerFSMBrewingState::NotReady( CoffeeMakerFSM& s )
{
    s.HwsPause();

    // Change the state
    s.SetState(CoffeeMakerFSM::BrewingPaused);
}

// Starting State: Brewing
// Event:          Done
//
void CoffeeMakerFSMBrewingState::Done( CoffeeMakerFSM& s )
{
    s.UiDone();
    s.HwsDone();
    s.VessDone();

    // Change the state
    s.SetState(CoffeeMakerFSM::Brewed);
}

//----------------------------------------------
// Brewed Actions and Transitions
//----------------------------------------------

// Starting State: Brewed
// Event:          Complete
//
void CoffeeMakerFSMBrewedState::Complete( CoffeeMakerFSM& s )
{
    s.UiComplete();
    s.HwsComplete();
    s.VessComplete();

    // Change the state
    s.SetState(CoffeeMakerFSM::Idle);
}

//----------------------------------------------
// BrewingPaused Actions and Transitions
//----------------------------------------------

// Starting State: BrewingPaused
// Event:          Ready
//
void CoffeeMakerFSMBrewingPausedState::Ready( CoffeeMakerFSM& s )
{
    s.HwsResume();

    // Change the state
    s.SetState(CoffeeMakerFSM::Brewing);
}

//----------------------------------------------
// Idle Actions and Transitions
//----------------------------------------------

// Starting State: Idle
// Event:          Start
//
void CoffeeMakerFSMIdleState::Start( CoffeeMakerFSM& s )
{
    s.HwsStart();
    s.VessStart();

    // Change the state
    s.SetState(CoffeeMakerFSM::Brewing);
}

//----------------------------------------------
// State Machine Constructor: CoffeeMakerFSM
//  set Initial State to: Idle
//
//----------------------------------------------
CoffeeMakerFSM::CoffeeMakerFSM() 
: itsState(&Idle)
{
    // Entry functions for: Idle
}

//  Get version information
//

}  // end namespace com_cmindustries_coffeeMakerFSM

