
#ifndef CPP_UNIT_QUERYTESTCASE_H
#define CPP_UNIT_QUERYTESTCASE_H

#include "TestCase.h"
#include "TestSuite.h"
#include "TestCaller.h"

class QueryTestCase : public TestCase
{
 public:
  QueryTestCase (std::string name) : TestCase (name) {}

  void			setUp ();
  static Test		*suite ();

 protected:
  void testSimpleQuery();
  void testSimpleSelectiveIterator();
};


#endif
