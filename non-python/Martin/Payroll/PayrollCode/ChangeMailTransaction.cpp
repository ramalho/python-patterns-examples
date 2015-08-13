#include "ChangeMailTransaction.h"
#include "MailMethod.h"

ChangeMailTransaction::~ChangeMailTransaction()
{
}

ChangeMailTransaction::ChangeMailTransaction(int empid, string address)
: ChangeMethodTransaction(empid)
, itsAddress(address)
{
}

PaymentMethod* ChangeMailTransaction::GetMethod() const
{
  return new MailMethod(itsAddress);
}
