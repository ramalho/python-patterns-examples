
#include "stdafx.h"
#include "TestRunnerDlg.h"
#include "GUITestResult.h"


void GUITestResult::addError (Test *test, CppUnitException *e)
{ 
    ExclusiveZone zone (m_syncObject);

    TestResult::addError (test, e); 
    m_runner->addError (this, test, e); 
}

void GUITestResult::addFailure (Test *test, CppUnitException *e)
{ 
    ExclusiveZone zone (m_syncObject);

    TestResult::addFailure (test, e); 
    m_runner->addFailure (this, test, e); 
}

void GUITestResult::endTest (Test *test)
{ 
    ExclusiveZone zone (m_syncObject);

    TestResult::endTest (test); 
    m_runner->endTest (this, test); 
}

