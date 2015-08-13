#include "MailMethod.h"

#include "Paycheck.h"

MailMethod::~MailMethod()
{
}

MailMethod::MailMethod(string address)
: itsAddress(address)
{
}

void MailMethod::Pay(Paycheck& pc)
{
  pc.SetField("Disposition", "Mail");
}
