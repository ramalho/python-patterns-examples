// CoffeeMakerIDlg.h : header file
//

#if !defined(AFX_COFFEEMAKERIDLG_H__0A683AA6_1E56_11D3_8F7D_00E09802EAB8__INCLUDED_)
#define AFX_COFFEEMAKERIDLG_H__0A683AA6_1E56_11D3_8F7D_00E09802EAB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCoffeeMakerIDlg dialog

#include "MIVAPI.h"
#include "Pollable.h"

using namespace com_cmindustries_m4_api;
using namespace com_cmindustries_pollable;

class CCoffeeMakerIDlg : public CDialog
                       , public API
{
// Construction
public:
	CCoffeeMakerIDlg(CWnd* pParent = NULL);	// standard constructor

    void SetPollable(Pollable& p) {itsPollable = &p;}

// Dialog Data
	//{{AFX_DATA(CCoffeeMakerIDlg)
	enum { IDD = IDD_COFFEEMAKERI_DIALOG };
	CButton	m_warmerOnCheckBox;
	CButton	m_valveOpenCheckBox;
	CButton	m_boilerOnCheckBox;
	CButton	m_boilerEmptyCheckBox;
	CButton	m_lightCheckBox;
	CButton	m_potNotEmptyRadioButton;
	CButton	m_potEmptyRadioButton;
	CButton	m_noPotRadioButton;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoffeeMakerIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

    virtual WarmerPlateStatus GetWarmerPlateStatus() const;
    virtual BoilerStatus      GetBoilerStatus() const;
    virtual BrewButtonStatus  GetBrewButtonStatus() const;

    virtual void SetBoilerState(BoilerHeaterState);
    virtual void SetWarmerState(WarmerState);
    virtual void SetIndicatorState(IndicatorState);
    virtual void SetReliefValveState(ReliefValveState);

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCoffeeMakerIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnnoPotRadioButton();
	afx_msg void OnpotEmptyRadioButton();
	afx_msg void OnpotNotEmptyRadioButton();
	afx_msg void OnbrewButton();
	afx_msg void OnboilerEmptyCheckbox();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    mutable bool m_brewButtonPressed;
    Pollable* itsPollable;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COFFEEMAKERIDLG_H__0A683AA6_1E56_11D3_8F7D_00E09802EAB8__INCLUDED_)
