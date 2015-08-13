#include "ChangeAddressTransaction.h"

ChangeAddressTransaction::~ChangeAddressTransaction()
{
}

ChangeAddressTransaction::ChangeAddressTransaction(int empid, string address)
  : ChangeEmployeeTransaction(empid)
    , itsAddress(address)
{
}

void ChangeAddressTransaction::Change(Employee& e)
{
  e.SetAddress(itsAddress);
}
