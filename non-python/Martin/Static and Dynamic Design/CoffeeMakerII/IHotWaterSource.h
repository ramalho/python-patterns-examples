#if !defined(AFX_IHOTWATERSOURCE_H__E1C796EA_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_)
#define AFX_IHOTWATERSOURCE_H__E1C796EA_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_

//---------------------
// IHotWaterSource
//  Processes actions that the CoffeeMakerFSM
//  directs to the HotWaterSource.

namespace com_cmindustries_coffeeMakerFSM
{
    class IHotWaterSource;
};

class com_cmindustries_coffeeMakerFSM::IHotWaterSource  
{
public:
	virtual ~IHotWaterSource();
    virtual void Start() = 0;
    virtual void Done() = 0;
    virtual void Complete() = 0;
    virtual void Pause() = 0;
    virtual void Resume() = 0;
};

#endif // !defined(AFX_IHOTWATERSOURCE_H__E1C796EA_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_)
