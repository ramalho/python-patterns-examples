// CoffeeMaker.h: interface for the CCoffeeMaker class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COFFEEMAKER_H__0A683AD2_1E56_11D3_8F7D_00E09802EAB8__INCLUDED_)
#define AFX_COFFEEMAKER_H__0A683AD2_1E56_11D3_8F7D_00E09802EAB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MIVAPI.h"
#include "Pollable.h"

namespace com_cmindustries_m4_app
{
    class CCoffeeMaker;
};

using com_cmindustries_m4_api::API;
using com_cmindustries_pollable::Pollable;

class com_cmindustries_m4_app::CCoffeeMaker : public Pollable
{
public:
	CCoffeeMaker(API& api);
	virtual ~CCoffeeMaker();

    virtual void Poll();
    virtual void Init();

private:
    enum State {waitToBrew
               ,brewingPotEmpty
               ,brewingAndWarming
               ,brewingComplete
               ,brewedPotRemoved
               ,emptyPotRemoved
               ,fullPotRemoved
               ,initial
    } itsState;

    void BoilerEmpty();
    void BoilerNotEmpty();
    void WarmerEmpty();
    void PotEmpty();
    void PotNotEmpty();
    void BrewButtonPushed();

    API& itsAPI;
    API::BoilerStatus      itsBoilerStatus;
    API::WarmerPlateStatus itsWarmerStatus;
};

#endif // !defined(AFX_COFFEEMAKER_H__0A683AD2_1E56_11D3_8F7D_00E09802EAB8__INCLUDED_)
