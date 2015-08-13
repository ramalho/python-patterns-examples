
#ifndef CPP_UNIT_PRODUCTPERSISTENCETESTCASE_H
#define CPP_UNIT_PRODUCTPERSISTENCETESTCASE_H

#include "TestCase.h"
#include "TestSuite.h"
#include "TestCaller.h"

class ProductPersistenceTestCase : public TestCase
{
 public:
  ProductPersistenceTestCase (std::string name) : TestCase (name) {}

  void			setUp ();
  static Test		*suite ();

 protected:
  void testWriteProduct();
  void testWriteAssembly();


};


#endif
