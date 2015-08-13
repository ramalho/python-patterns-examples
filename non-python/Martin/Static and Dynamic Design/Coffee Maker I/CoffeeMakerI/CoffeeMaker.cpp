// CoffeeMaker.cpp: implementation of the CCoffeeMaker class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CoffeeMaker.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

using namespace com_cmindustries_m4_api;
using namespace com_cmindustries_m4_app;

CCoffeeMaker::CCoffeeMaker(API& api)
: itsAPI(api)
, itsBoilerStatus(API::boilerEmpty)
, itsWarmerStatus(API::warmerEmpty)
, itsState(initial)
{
}

void CCoffeeMaker::Init()
{
    itsState = waitToBrew;
    itsAPI.SetIndicatorState(API::indicatorOff);
    itsAPI.SetBoilerState(API::boilerOff);
    itsAPI.SetWarmerState(API::warmerOff);
    itsAPI.SetReliefValveState(API::valveClosed);
}

CCoffeeMaker::~CCoffeeMaker()
{

}

void CCoffeeMaker::Poll()
{
    if (itsState == initial) Init();

    API::BoilerStatus newBoilerStatus = itsAPI.GetBoilerStatus();
    API::WarmerPlateStatus newWarmerStatus = itsAPI.GetWarmerPlateStatus();
    API::BrewButtonStatus newBrewButtonStatus = itsAPI.GetBrewButtonStatus();

    if (itsBoilerStatus != newBoilerStatus)
    {
        if (newBoilerStatus == API::boilerNotEmpty)
            BoilerNotEmpty();
        else
            BoilerEmpty();
        itsBoilerStatus = newBoilerStatus;
    }

    if (itsWarmerStatus != newWarmerStatus)
    {
        if (newWarmerStatus == API::warmerEmpty)
            WarmerEmpty();
        else if (newWarmerStatus == API::potEmpty)
            PotEmpty();
        else
            PotNotEmpty();
        itsWarmerStatus = newWarmerStatus;
    }


    if (newBrewButtonStatus == API::brewButtonPushed)
        BrewButtonPushed();

}

void CCoffeeMaker::BoilerEmpty()
{
    switch (itsState)
    {
    case waitToBrew:
    break;

    case brewingPotEmpty:
        itsState = waitToBrew;
        itsAPI.SetBoilerState(API::boilerOff);
        itsAPI.SetIndicatorState(API::indicatorOn);
    break;

    case brewingAndWarming:
        itsState = brewingComplete;
        itsAPI.SetBoilerState(API::boilerOff);
        itsAPI.SetIndicatorState(API::indicatorOn);
    break;
    
    case brewingComplete:
    break;

    case brewedPotRemoved:
    break;

    case emptyPotRemoved:
        itsState = waitToBrew;
        itsAPI.SetBoilerState(API::boilerOff);
        itsAPI.SetIndicatorState(API::indicatorOn);
        itsAPI.SetReliefValveState(API::valveClosed);
    break;

    case fullPotRemoved:
        itsState = brewedPotRemoved;
        itsAPI.SetBoilerState(API::boilerOff);
        itsAPI.SetIndicatorState(API::indicatorOn);
        itsAPI.SetReliefValveState(API::valveClosed);
    break;
    }
}

void CCoffeeMaker::BoilerNotEmpty()
{
    switch (itsState)
    {
    case waitToBrew:
        itsAPI.SetIndicatorState(API::indicatorOff);
    break;

    case brewingPotEmpty:
    break;

    case brewingAndWarming:
    break;
    
    case brewingComplete:
    break;

    case brewedPotRemoved:
    break;

    case emptyPotRemoved:
    break;

    case fullPotRemoved:
    break;
    }
}

void CCoffeeMaker::WarmerEmpty()
{
    switch (itsState)
    {
    case waitToBrew:
    break;

    case brewingPotEmpty:
        itsState=emptyPotRemoved;
        itsAPI.SetReliefValveState(API::valveOpen);
        itsAPI.SetBoilerState(API::boilerOff);
    break;

    case brewingAndWarming:
        itsState = fullPotRemoved;
        itsAPI.SetReliefValveState(API::valveOpen);
        itsAPI.SetBoilerState(API::boilerOff);
        itsAPI.SetWarmerState(API::warmerOff);
    break;
    
    case brewingComplete:
        itsState=brewedPotRemoved;
        itsAPI.SetWarmerState(API::warmerOff);
    break;

    case brewedPotRemoved:
    break;

    case emptyPotRemoved:
    break;

    case fullPotRemoved:
    break;
    }
}

void CCoffeeMaker::PotEmpty()
{
    switch (itsState)
    {
    case waitToBrew:
    break;

    case brewingPotEmpty:
    break;

    case brewingAndWarming:
        itsState=brewingPotEmpty;
        itsAPI.SetWarmerState(API::warmerOff);
    break;
    
    case brewingComplete:
        itsState=waitToBrew;
        itsAPI.SetWarmerState(API::warmerOff);
        itsAPI.SetIndicatorState(API::indicatorOff);
    break;

    case brewedPotRemoved:
        itsState=waitToBrew;
        itsAPI.SetIndicatorState(API::indicatorOff);
    break;

    case emptyPotRemoved:
        itsState=brewingPotEmpty;
        itsAPI.SetReliefValveState(API::valveClosed);
        itsAPI.SetBoilerState(API::boilerOn);
    break;

    case fullPotRemoved:
        itsState=brewingPotEmpty;
        itsAPI.SetReliefValveState(API::valveClosed);
        itsAPI.SetBoilerState(API::boilerOn);
    break;
    }
}

void CCoffeeMaker::PotNotEmpty()
{
    switch (itsState)
    {
    case waitToBrew:
    break;

    case brewingPotEmpty:
        itsState=brewingAndWarming;
        itsAPI.SetWarmerState(API::warmerOn);
    break;

    case brewingAndWarming:
    break;
    
    case brewingComplete:
    break;

    case brewedPotRemoved:
        itsState=brewingComplete;
        itsAPI.SetWarmerState(API::warmerOn);
    break;

    case emptyPotRemoved:
        itsState=brewingAndWarming;
        itsAPI.SetReliefValveState(API::valveClosed);
        itsAPI.SetBoilerState(API::boilerOn);
        itsAPI.SetWarmerState(API::warmerOn);
    break;

    case fullPotRemoved:
        itsState=brewingAndWarming;
        itsAPI.SetReliefValveState(API::valveClosed);
        itsAPI.SetBoilerState(API::boilerOn);
        itsAPI.SetWarmerState(API::warmerOn);
    break;
    }
}

void CCoffeeMaker::BrewButtonPushed()
{
    switch (itsState)
    {
    case waitToBrew:
        if (itsBoilerStatus == API::boilerNotEmpty
            && itsWarmerStatus == API::potEmpty)
        {
            itsState = brewingPotEmpty;
            itsAPI.SetReliefValveState(API::valveClosed);
            itsAPI.SetBoilerState(API::boilerOn);
            itsAPI.SetIndicatorState(API::indicatorOff);
        }
    break;

    case brewingPotEmpty:
    break;

    case brewingAndWarming:
    break;
    
    case brewingComplete:
    break;

    case brewedPotRemoved:
    break;

    case emptyPotRemoved:
    break;

    case fullPotRemoved:
    break;
    }
}

