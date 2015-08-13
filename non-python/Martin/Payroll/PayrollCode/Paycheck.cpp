#include "Paycheck.h"

Paycheck::~Paycheck()
{
}

Paycheck::Paycheck(const Date& payPeriodStartDate,
		   const Date& payPeriodEndDate)
: itsPayPeriodStartDate(payPeriodStartDate)
, itsPayPeriodEndDate(payPeriodEndDate)
{
}

void Paycheck::SetGrossPay(double grossPay)
{
  itsGrossPay = grossPay;
}

void Paycheck::SetNetPay(double netPay)
{
  itsNetPay = netPay;
}

void Paycheck::SetDeductions(double deductions)
{
  itsDeductions = deductions;
}

void Paycheck::SetField(string name, string value)
{
  itsFields[name] = value;
}

string Paycheck::GetField(string name)
{
  return itsFields[name];
}
