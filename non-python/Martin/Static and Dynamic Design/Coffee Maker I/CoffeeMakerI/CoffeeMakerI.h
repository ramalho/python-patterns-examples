// CoffeeMakerI.h : main header file for the COFFEEMAKERI application
//

#if !defined(AFX_COFFEEMAKERI_H__0A683AA4_1E56_11D3_8F7D_00E09802EAB8__INCLUDED_)
#define AFX_COFFEEMAKERI_H__0A683AA4_1E56_11D3_8F7D_00E09802EAB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

namespace com_cmindustries_m4_app
{
    class CCoffeeMaker;
}; // fwd dcl.

/////////////////////////////////////////////////////////////////////////////
// CCoffeeMakerIApp:
// See CoffeeMakerI.cpp for the implementation of this class
//

class CCoffeeMakerIApp : public CWinApp
{
public:
	CCoffeeMakerIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoffeeMakerIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

    virtual BOOL OnIdle(LONG c);

	//{{AFX_MSG(CCoffeeMakerIApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    com_cmindustries_m4_app::CCoffeeMaker* itsCoffeeMaker;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COFFEEMAKERI_H__0A683AA4_1E56_11D3_8F7D_00E09802EAB8__INCLUDED_)
