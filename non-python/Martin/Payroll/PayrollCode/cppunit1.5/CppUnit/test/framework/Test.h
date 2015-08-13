

#ifndef CPPUNIT_TEST_H
#define CPPUNIT_TEST_H

#include <string>

class TestResult;

/*
 * A Test can be run and collect its results.
 * See TestResult.
 * 
 */


class Test
{
public:
    virtual                ~Test () = 0;

    virtual void           run (TestResult *result)    = 0;
    virtual int            countTestCases ()           = 0;
    virtual std::string    toString ()                 = 0;


};

inline Test::~Test ()
{}



// Runs a test and collects its result in a TestResult instance.
inline void Test::run (TestResult *result)
{}


// Counts the number of test cases that will be run by this test.
inline int Test::countTestCases ()
{ return 0; }


// Returns the name of the test instance. 
inline std::string Test::toString ()
{ return ""; }


#endif

