#if !defined(AFX_IUI_H__E1C796E9_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_)
#define AFX_IUI_H__E1C796E9_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_

//----------------
// IUI
//  Processes actions that the CoffeeMakerFSM
//  directs to the UI

namespace com_cmindustries_coffeeMakerFSM
{
    class IUI;
};

class com_cmindustries_coffeeMakerFSM::IUI  
{
public:
	virtual ~IUI();
    virtual void Complete() = 0;
    virtual void Done() = 0;
};

#endif // !defined(AFX_IUI_H__E1C796E9_2A3A_11D3_8F7E_00E09802EAB8__INCLUDED_)
