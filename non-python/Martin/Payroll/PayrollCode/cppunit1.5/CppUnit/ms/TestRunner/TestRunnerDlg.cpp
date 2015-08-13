// TestRunnerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mmsystem.h"
#include "TestRunnerDlg.h"
#include "ActiveTest.h"
#include "GUITestResult.h"
#include "ProgressBar.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// TestRunnerDlg dialog


TestRunnerDlg::TestRunnerDlg(CWnd* pParent /*=NULL*/)
    : CDialog(TestRunnerDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(TestRunnerDlg)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT

    m_testsProgress     = 0;
    m_tests             = 0;
    m_selectedTest      = 0;
}


void TestRunnerDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(TestRunnerDlg)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TestRunnerDlg, CDialog)
    //{{AFX_MSG_MAP(TestRunnerDlg)
    ON_BN_CLICKED(ID_RUN, OnRun)
    ON_BN_CLICKED(ID_STOP, OnStop)
    ON_CBN_SELCHANGE(IDC_COMBO_TEST, OnSelchangeComboTest)
    ON_WM_PAINT()
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TestRunnerDlg message handlers

BOOL TestRunnerDlg::OnInitDialog() 
{
    CDialog::OnInitDialog();
    
    CListCtrl   *listCtrl = (CListCtrl *)GetDlgItem (IDC_LIST);
    CComboBox   *comboBox = (CComboBox *)GetDlgItem (IDC_COMBO_TEST);

    ASSERT (listCtrl);
    ASSERT (comboBox);

    listCtrl->InsertColumn (0,"Type", LVCFMT_LEFT, 2 * listCtrl->GetStringWidth ("Type"), 1);
    listCtrl->InsertColumn (1,"Name", LVCFMT_LEFT, 20 * listCtrl->GetStringWidth ("#"), 2);
    listCtrl->InsertColumn (2,"Failed Condition", LVCFMT_LEFT, 1.75 * listCtrl->GetStringWidth ("Failed Condition"), 3);
    listCtrl->InsertColumn (3,"Line Number", LVCFMT_LEFT, 1.5 * listCtrl->GetStringWidth ("Line Number"), 4);
    listCtrl->InsertColumn (4,"File Name", LVCFMT_LEFT, 4.0 * listCtrl->GetStringWidth ("File Name"), 5);

    int numberOfCases = 0;

    for (std::vector<Test *>::iterator it = m_tests->begin (); it != m_tests->end (); ++it)
    {
        comboBox->AddString ((*it)->toString ().c_str ());
        m_selectedTest = *it;
        numberOfCases++;
    }

    if (numberOfCases > 0)
        comboBox->SetCurSel (numberOfCases -1);
    else
        beRunDisabled ();

    m_testsProgress = new ProgressBar (this, CRect (50, 85, 50 + 425, 85 + 25));

    reset ();
    
    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}

TestRunnerDlg::~TestRunnerDlg ()
{ 
    freeState ();
    delete m_testsProgress;
}

void TestRunnerDlg::OnRun() 
{
	if (m_selectedTest == 0)
		return;

    freeState       (); 
    reset           ();

    beRunning       ();

    int numberOfTests = m_selectedTest->countTestCases ();

    m_testsProgress->start (numberOfTests);

    m_result            = new GUITestResult ((TestRunnerDlg *)this);
    m_activeTest        = new ActiveTest (m_selectedTest);

    m_testStartTime     = timeGetTime ();

    m_activeTest->run (m_result);

    m_testEndTime       = timeGetTime ();

}


void TestRunnerDlg::addListEntry (std::string type, TestResult *result, Test *test, CppUnitException *e)
{
    char        stage [80];
    LV_ITEM     lvi;
    CListCtrl   *listCtrl       = (CListCtrl *)GetDlgItem (IDC_LIST);
    int         currentEntry    = result->testErrors () + result->testFailures () -1;

    sprintf (stage, "%s", type.c_str ());

    lvi.mask        = LVIF_TEXT;
    lvi.iItem       = currentEntry;
    lvi.iSubItem    = 0;
    lvi.pszText     = stage;
    lvi.iImage      = 0;
    lvi.stateMask   = 0;
    lvi.state       = 0;

    listCtrl->InsertItem (&lvi);

    // Set class string
    listCtrl->SetItemText (currentEntry, 1, test->toString ().c_str ());

    // Set the asserted text
    listCtrl->SetItemText(currentEntry, 2, e->what ());

    // Set the line number
    if (e->lineNumber () == CPPUNIT_UNKNOWNLINENUMBER)
        sprintf (stage, "<unknown>");
    else
        sprintf (stage, "%ld", e->lineNumber ());

    listCtrl->SetItemText(currentEntry, 3, stage);

    // Set the file name
    listCtrl->SetItemText(currentEntry, 4, e->fileName ().c_str ());

    listCtrl->RedrawItems (currentEntry, currentEntry);
    listCtrl->UpdateWindow ();

}



void TestRunnerDlg::addError (TestResult *result, Test *test, CppUnitException *e)
{
    addListEntry ("Error", result, test, e);
    m_errors++;

    updateCountsDisplay ();

}

void TestRunnerDlg::addFailure (TestResult *result, Test *test, CppUnitException *e)
{
    addListEntry ("Failure", result, test, e);
    m_failures++;

    updateCountsDisplay ();

}


void TestRunnerDlg::endTest (TestResult *result, Test *test)
{
	if (m_selectedTest == 0)
		return;

    m_testsRun++;
    updateCountsDisplay ();
    m_testsProgress->step (m_failures == 0 && m_errors == 0);

    m_testEndTime   = timeGetTime ();

    updateCountsDisplay ();

    if (m_testsRun >= m_selectedTest->countTestCases ())
        beIdle ();
}


void TestRunnerDlg::beRunning ()
{
    CButton *runButton = (CButton *)GetDlgItem (ID_RUN);
    CButton *closeButton = (CButton *)GetDlgItem (IDOK);

    runButton->EnableWindow (FALSE);
    closeButton->EnableWindow (FALSE);

}


void TestRunnerDlg::beIdle ()
{
    CButton *runButton = (CButton *)GetDlgItem (ID_RUN);
    CButton *closeButton = (CButton *)GetDlgItem (IDOK);

    runButton->EnableWindow (TRUE);
    closeButton->EnableWindow (TRUE);

}

void TestRunnerDlg::beRunDisabled ()
{
    CButton *runButton = (CButton *)GetDlgItem (ID_RUN);
    CButton *closeButton = (CButton *)GetDlgItem (IDOK);
    CButton *stopButton = (CButton *)GetDlgItem (ID_STOP);

    runButton->EnableWindow (FALSE);
    stopButton->EnableWindow (FALSE);
    closeButton->EnableWindow (TRUE);

}




void TestRunnerDlg::freeState ()
{
    delete m_activeTest;
    delete m_result;

}

void TestRunnerDlg::reset ()
{
    m_testsRun      = 0;
    m_errors        = 0;
    m_failures      = 0;
    m_testEndTime   = m_testStartTime;

    updateCountsDisplay ();

    m_activeTest    = 0;
    m_result        = 0;

    CListCtrl *listCtrl = (CListCtrl *)GetDlgItem (IDC_LIST);

    listCtrl->DeleteAllItems ();
    m_testsProgress->reset ();

}


void TestRunnerDlg::updateCountsDisplay ()
{
    CStatic *statTestsRun   = (CStatic *)GetDlgItem (IDC_STATIC_RUNS);
    CStatic *statErrors     = (CStatic *)GetDlgItem (IDC_STATIC_ERRORS);
    CStatic *statFailures   = (CStatic *)GetDlgItem (IDC_STATIC_FAILURES);
    CEdit *editTime         = (CEdit *)GetDlgItem (IDC_EDIT_TIME);

    CString argumentString;

    argumentString.Format ("%d", m_testsRun);
    statTestsRun    ->SetWindowText (argumentString);

    argumentString.Format ("%d", m_errors);
    statErrors      ->SetWindowText (argumentString);

    argumentString.Format ("%d", m_failures);
    statFailures    ->SetWindowText (argumentString);

    argumentString.Format ("Execution time: %3.3lf seconds", (m_testEndTime - m_testStartTime) / 1000.0);
    editTime        ->SetWindowText (argumentString);


}

void TestRunnerDlg::OnStop() 
{
    if (m_result)
        m_result->stop ();

    beIdle ();
    
}

void TestRunnerDlg::OnOK() 
{
    if (m_result)
        m_result->stop ();

    CDialog::OnOK ();
}

void TestRunnerDlg::OnSelchangeComboTest() 
{
    CComboBox   *testsSelection = (CComboBox *)GetDlgItem (IDC_COMBO_TEST);

    int currentSelection = testsSelection->GetCurSel ();

    if (currentSelection >= 0 && currentSelection < m_tests->size ())
    {
        m_selectedTest = *(m_tests->begin () + currentSelection);
        beIdle ();

    }
    else
    {
        m_selectedTest = 0;
        beRunDisabled ();

    }

    freeState ();
    reset ();

}

void TestRunnerDlg::OnPaint() 
{
    CPaintDC dc (this); 
    
    m_testsProgress->paint (dc);    
}
