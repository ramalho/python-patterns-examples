#if !defined(AFX_IVESSELCLIENT_H__E1C796E8_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_)
#define AFX_IVESSELCLIENT_H__E1C796E8_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_

//--------------------
// IVesselClient
//  Catches events from the Vessel
//  of the coffee Maker

namespace com_cmindustries_coffeeMakerFSM
{
    class IVesselClient;
};

class com_cmindustries_coffeeMakerFSM::IVesselClient  
{
public:
	virtual ~IVesselClient();
    virtual void Ready() = 0;
    virtual void NotReady() = 0;
    virtual void Done() = 0;
    virtual void Complete() = 0;
};

#endif // !defined(AFX_IVESSELCLIENT_H__E1C796E8_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_)
