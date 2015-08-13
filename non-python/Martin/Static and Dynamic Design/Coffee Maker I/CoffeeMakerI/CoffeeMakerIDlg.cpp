// CoffeeMakerIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CoffeeMakerI.h"
#include "CoffeeMakerIDlg.h"
#include "assert.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCoffeeMakerIDlg dialog

CCoffeeMakerIDlg::CCoffeeMakerIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCoffeeMakerIDlg::IDD, pParent)
    , m_brewButtonPressed(false)
{
	//{{AFX_DATA_INIT(CCoffeeMakerIDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCoffeeMakerIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCoffeeMakerIDlg)
	DDX_Control(pDX, warmerOnCheckBox, m_warmerOnCheckBox);
	DDX_Control(pDX, valveOpenCheckBox, m_valveOpenCheckBox);
	DDX_Control(pDX, boilerOnCheckBox, m_boilerOnCheckBox);
	DDX_Control(pDX, boilerEmptyCheckbox, m_boilerEmptyCheckBox);
	DDX_Control(pDX, lightCheckBox, m_lightCheckBox);
	DDX_Control(pDX, potNotEmptyRadioButton, m_potNotEmptyRadioButton);
	DDX_Control(pDX, potEmptyRadioButton, m_potEmptyRadioButton);
	DDX_Control(pDX, noPotRadioButton, m_noPotRadioButton);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCoffeeMakerIDlg, CDialog)
	//{{AFX_MSG_MAP(CCoffeeMakerIDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(noPotRadioButton, OnnoPotRadioButton)
	ON_BN_CLICKED(potEmptyRadioButton, OnpotEmptyRadioButton)
	ON_BN_CLICKED(potNotEmptyRadioButton, OnpotNotEmptyRadioButton)
	ON_BN_CLICKED(brewButton, OnbrewButton)
	ON_BN_CLICKED(boilerEmptyCheckbox, OnboilerEmptyCheckbox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCoffeeMakerIDlg message handlers

BOOL CCoffeeMakerIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
    assert(itsPollable);
    itsPollable->Poll();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCoffeeMakerIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCoffeeMakerIDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCoffeeMakerIDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCoffeeMakerIDlg::OnnoPotRadioButton() 
{
    m_potEmptyRadioButton.SetCheck(false);
    m_potNotEmptyRadioButton.SetCheck(false);
    itsPollable->Poll();
}

void CCoffeeMakerIDlg::OnpotEmptyRadioButton() 
{
    m_noPotRadioButton.SetCheck(false);
    m_potNotEmptyRadioButton.SetCheck(false);
    itsPollable->Poll();
}



void CCoffeeMakerIDlg::OnpotNotEmptyRadioButton() 
{
    m_noPotRadioButton.SetCheck(false);
    m_potEmptyRadioButton.SetCheck(false);
    itsPollable->Poll();
}

API::WarmerPlateStatus CCoffeeMakerIDlg::GetWarmerPlateStatus() const
{
    if (m_potEmptyRadioButton.GetCheck())
        return potEmpty;
    else if (m_potNotEmptyRadioButton.GetCheck())
        return potNotEmpty;
    else if (m_noPotRadioButton.GetCheck())
        return warmerEmpty;
}

API::BoilerStatus CCoffeeMakerIDlg::GetBoilerStatus() const
{
    if (m_boilerEmptyCheckBox.GetCheck())
        return boilerEmpty;
    else
        return boilerNotEmpty;
}

API::BrewButtonStatus CCoffeeMakerIDlg::GetBrewButtonStatus() const
{
    if (m_brewButtonPressed)
    {
        m_brewButtonPressed = false;
        return brewButtonPushed;
    }
    else
        return brewButtonNotPushed;
}

void CCoffeeMakerIDlg::SetBoilerState(BoilerHeaterState s)
{
    m_boilerOnCheckBox.SetCheck(s == boilerOn);
}

void CCoffeeMakerIDlg::SetWarmerState(WarmerState s)
{
    m_warmerOnCheckBox.SetCheck(s == warmerOn);
}

void CCoffeeMakerIDlg::SetIndicatorState(IndicatorState s)
{
    m_lightCheckBox.SetCheck(s == indicatorOn);
}

void CCoffeeMakerIDlg::SetReliefValveState(ReliefValveState s)
{
    m_valveOpenCheckBox.SetCheck(s == valveOpen);
}

void CCoffeeMakerIDlg::OnbrewButton() 
{
    m_brewButtonPressed = true;	
    itsPollable->Poll();
}

void CCoffeeMakerIDlg::OnboilerEmptyCheckbox() 
{
    itsPollable->Poll();	
}
