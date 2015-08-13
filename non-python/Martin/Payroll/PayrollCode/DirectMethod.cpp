#include "DirectMethod.h"
#include "Paycheck.h"

DirectMethod::~DirectMethod()
{
}

DirectMethod::DirectMethod(string bank, string account)
: itsBank(bank)
, itsAccount(account)
{
}

void DirectMethod::Pay(Paycheck& pc)
{
  pc.SetField("Disposition", "Direct");
}

























































































