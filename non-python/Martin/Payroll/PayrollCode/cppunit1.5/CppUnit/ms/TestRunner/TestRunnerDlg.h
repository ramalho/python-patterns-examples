#if !defined(AFX_TESTRUNNERDLG_H)
#define AFX_TESTRUNNERDLG_H

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// TestRunnerDlg.h : header file
//

#include <vector>


#ifndef CPPUNIT_ACTIVETEST_H
#include "ActiveTest.h"
#endif

#include "Resource.h"


class ProgressBar;
class CppUnitException;


/////////////////////////////////////////////////////////////////////////////
// TestRunnerDlg dialog

class AFX_CLASS_EXPORT TestRunnerDlg : public CDialog
{
// Construction
public:
                    TestRunnerDlg       (CWnd* pParent = NULL);
                    ~TestRunnerDlg      ();

    void            setTests            (std::vector<Test *> *test);

    void            addError            (TestResult *result, Test *test, CppUnitException *e);
    void            addFailure          (TestResult *result, Test *test, CppUnitException *e);
    void            endTest             (TestResult *result, Test *test);

// Dialog Data
    //{{AFX_DATA(TestRunnerDlg)
    enum { IDD = IDD_DIALOG_TESTRUNNER };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(TestRunnerDlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(TestRunnerDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnRun();
    afx_msg void OnStop();
    virtual void OnOK();
    afx_msg void OnSelchangeComboTest();
    afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

    ProgressBar     *m_testsProgress;
    std::vector<Test *>  *m_tests;
    Test            *m_selectedTest;
    ActiveTest      *m_activeTest;
    TestResult      *m_result;
    int             m_testsRun;
    int             m_errors;
    int             m_failures;
    DWORD           m_testStartTime;
    DWORD           m_testEndTime;

    void            addListEntry        (std::string type, TestResult *result, Test *test, CppUnitException *e);
    void            beIdle              ();
    void            beRunning           ();
    void            beRunDisabled       ();
    void            reset               ();
    void            freeState           ();
    void            updateCountsDisplay ();

};


inline void TestRunnerDlg::setTests (std::vector<Test *> *tests)
{ m_tests = tests; }




/////////////////////////////////////////////////////////////////////////////
// A Wrapper


class AFX_CLASS_EXPORT TestRunner 
{
    std::vector<Test *>  m_tests;

public:
                    TestRunner () {}
                    ~TestRunner () 
                    {
                        for (std::vector<Test *>::iterator it = m_tests.begin (); it != m_tests.end (); ++it)
                            delete *it;
                    }

    void            run () 
                    { 
                        TestRunnerDlg dlg; 

                        dlg.setTests (&m_tests);
                        dlg.DoModal (); 
                    }

    void            addTest (Test *test) 
                    { m_tests.push_back (test); }


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTRUNNERDLG_H)
