#include "ChangeSalariedTransaction.h"
#include "MonthlySchedule.h"
#include "SalariedClassification.h"

ChangeSalariedTransaction::~ChangeSalariedTransaction()
{
}

ChangeSalariedTransaction::ChangeSalariedTransaction(int empid, double salary)
: ChangeClassificationTransaction(empid)
, itsSalary(salary)
{
}

PaymentSchedule* ChangeSalariedTransaction::GetSchedule() const
{
  return new MonthlySchedule();
}

PaymentClassification* ChangeSalariedTransaction::GetClassification() const
{
  return new SalariedClassification(itsSalary);
}
