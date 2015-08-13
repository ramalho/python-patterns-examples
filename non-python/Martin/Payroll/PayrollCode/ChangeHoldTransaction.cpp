#include "ChangeHoldTransaction.h"
#include "HoldMethod.h"

ChangeHoldTransaction::~ChangeHoldTransaction()
{
}

ChangeHoldTransaction::ChangeHoldTransaction(int empid)
: ChangeMethodTransaction(empid)
{
}

PaymentMethod* ChangeHoldTransaction::GetMethod() const
{
  return new HoldMethod();
}
