#if !defined(AFX_IHOTWATERSOURCECLIENT_H__E1C796E7_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_)
#define AFX_IHOTWATERSOURCECLIENT_H__E1C796E7_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_

//-----------------------
// IHotWaterSourceClient
//  Catches events from the HotWaterSource
//  of the coffee maker.

namespace com_cmindustries_coffeeMakerFSM
{
    class IHotWaterSourceClient;
};

class com_cmindustries_coffeeMakerFSM::IHotWaterSourceClient  
{
public:
	virtual ~IHotWaterSourceClient();
    virtual void Done() = 0;
};

#endif // !defined(AFX_IHOTWATERSOURCECLIENT_H__E1C796E7_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_)
