#if !defined(AFX_IVESSEL_H__E1C796EB_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_)
#define AFX_IVESSEL_H__E1C796EB_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_

//-------------------------
// IVessel
//  Processes actions that the CoffeeMakerFSM
//  directs to the Vessel

namespace com_cmindustries_coffeeMakerFSM
{
    class IVessel;
};

class com_cmindustries_coffeeMakerFSM::IVessel  
{
public:
	virtual ~IVessel();
    virtual void Start() = 0;
    virtual void Complete() = 0;
    virtual void Done() = 0;
};

#endif // !defined(AFX_IVESSEL_H__E1C796EB_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_)
