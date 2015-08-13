#include "HoldMethod.h"

#include "Paycheck.h"

HoldMethod::~HoldMethod()
{
}

void HoldMethod::Pay(Paycheck& pc)
{
  pc.SetField("Disposition", "Hold");
}
