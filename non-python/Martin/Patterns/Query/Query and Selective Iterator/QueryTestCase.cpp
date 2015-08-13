#include "QueryTestCase.h"
#include "OddQuery.h"

void QueryTestCase::setUp ()
{
}

void QueryTestCase::testSimpleQuery()
{
  OddQuery oddQuery;
  assert(oddQuery.match(1));
  assert(oddQuery.match(3));
}

void QueryTestCase::testSimpleSelectiveIterator()
{
  SelectiveIterator
}

//------------------------------------------
template <class T> 
TestCaller<T>* makeTestCaller(char* name, void (T::*f)() )
{
  return new TestCaller<T>(name, f);
}

Test *QueryTestCase::suite ()
{
  TestSuite *testSuite = new TestSuite ("QueryTestCase");
    testSuite->addTest (makeTestCaller("testSimpleQuery", &QueryTestCase::testSimpleQuery));   
    testSuite->addTest (makeTestCaller("testSimpleSelectiveIterator", &QueryTestCase::testSimpleSelectiveIterator));

  return testSuite;
}


