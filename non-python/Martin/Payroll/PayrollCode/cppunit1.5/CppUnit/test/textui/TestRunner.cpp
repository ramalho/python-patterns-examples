

/*
 * A command line based tool to run tests.
 * TestRunner expects as its only argument the name of a TestCase class.
 * TestRunner prints out a trace as the tests are executed followed by a
 * summary at the end.
 *
 * You can add to the tests that the TestRunner knows about by 
 * making additional calls to "addTest (...)" in main.
 *
 * Here is the synopsis:
 *
 * TestRunner [-wait] ExampleTestCase
 *
 */

#include <iostream>
#include <vector>

#include "TextTestResult.h"
#include "ExampleTestCase.h"


using namespace std;

typedef pair<string, Test *>           mapping;
typedef vector<pair<string, Test *> >   mappings;

class TestRunner
{
protected:
    bool                                m_wait;
    vector<pair<string,Test *> >        m_mappings;

public:
	            TestRunner    () : m_wait (false) {}
                ~TestRunner   ();

    void        run           (int ac, char **av);
    void        addTest       (string name, Test *test)
    { m_mappings.push_back (mapping (name, test)); }

protected:
    void        run (Test *test);
    void        printBanner ();

};



void TestRunner::printBanner ()
{
    cout << "Usage: driver [ -wait ] testName, where name is the name of a test case class" << endl;
}


void TestRunner::run (int ac, char **av)
{
    string  testCase;
    int     numberOfTests = 0;

    for (int i = 1; i < ac; i++) {

        if (string (av [i]) == "-wait") {
            m_wait = true;
            continue;
        }

        testCase = av [i];

        if (testCase == "") {
            printBanner ();
            return;
        }

        Test *testToRun = NULL;

        for (mappings::iterator it = m_mappings.begin ();
                it != m_mappings.end ();
                ++it) {
            if ((*it).first == testCase) {
                testToRun = (*it).second;
                run (testToRun);

            }
        }

        numberOfTests++;

        if (!testToRun) {
            cout << "Test " << testCase << " not found." << endl;
            return;

        } 


    }

    if (numberOfTests == 0) {
        printBanner ();
        return;        
    }

    if (m_wait) {
        cout << "<RETURN> to continue" << endl;
        cin.get ();

    }


}


TestRunner::~TestRunner ()
{
    for (mappings::iterator it = m_mappings.begin ();
             it != m_mappings.end ();
             ++it)
        delete it->second;

}


void TestRunner::run (Test *test)
{
    TextTestResult  result;

    test->run (&result);

    cout << result << endl;
}


int main (int ac, char **av)
{
    TestRunner runner;

    runner.addTest ("ExampleTestCase", ExampleTestCase::suite ());
    runner.run (ac, av);

    return 0;
}


