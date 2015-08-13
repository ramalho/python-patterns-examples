#include "ChangeMethodTransaction.h"

ChangeMethodTransaction::~ChangeMethodTransaction()
{
}

ChangeMethodTransaction::ChangeMethodTransaction(int empid)
: ChangeEmployeeTransaction(empid)
{
}

void ChangeMethodTransaction::Change(Employee& e)
{
  e.SetMethod(GetMethod());
}
