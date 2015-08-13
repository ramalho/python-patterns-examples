#ifndef GUID_A0346CE0_2AD4_11d3_8F7E_00E09802EAB8
#define GUID_A0346CE0_2AD4_11d3_8F7E_00E09802EAB8

#include "coffeeMakerFSM.h"
#include "IHotWaterSource.h"
#include "IHotWaterSourceClient.h"
#include "IUI.h"
#include "IUIClient.h"
#include "IVessel.h"
#include "IVesselClient.h"

// CoffeeMakerFSM_I
//


using namespace com_cmindustries_coffeeMakerFSM;

namespace com_cmindustries_coffeeMakerFSM_I
{
    class CoffeeMakerFSM_I;
};

class com_cmindustries_coffeeMakerFSM_I::CoffeeMakerFSM_I 
: public virtual CoffeeMakerFSM
, public virtual IUIClient
, public virtual IHotWaterSourceClient
, public virtual IVesselClient
{
public:
    CoffeeMakerFSM_I(IUI* ui
                    ,IHotWaterSource* hws
                    ,IVessel* vess
                    )
    : itsUI(ui)
    , itsHws(hws)
    , itsVess(vess)
    {}
    virtual ~CoffeeMakerFSM_I() {}

    virtual void UiComplete()   {itsUI->Complete();}
    virtual void UiDone()       {itsUI->Done();}

    virtual void HwsStart()     {itsHws->Start();}
    virtual void HwsDone()      {itsHws->Done();}
    virtual void HwsComplete()  {itsHws->Complete();}
    virtual void HwsPause()     {itsHws->Pause();}
    virtual void HwsResume()    {itsHws->Resume();}

    virtual void VessStart()    {itsVess->Start();}
    virtual void VessComplete() {itsVess->Complete();}
    virtual void VessDone()     {itsVess->Done();}

private:
    IUI* itsUI;
    IHotWaterSource* itsHws;
    IVessel* itsVess;
};

#endif // GUID_A0346CE0_2AD4_11d3_8F7E_00E09802EAB8