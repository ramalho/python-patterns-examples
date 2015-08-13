#include "PaydayTransaction.h"
#include "PayrollDatabase.h"
#include "Paycheck.h"
#include "Date.h"
#include "Employee.h"

#include <list>

extern PayrollDatabase GpayrollDatabase;

PaydayTransaction::~PaydayTransaction()
{
}

PaydayTransaction::PaydayTransaction(Date payDate)
  :itsPayDate(payDate)
{
}

void PaydayTransaction::Execute()
{
  list<int> empIds;
  GpayrollDatabase.GetAllEmployeeIds(empIds);
  
  list<int>::iterator i = empIds.begin();
  for (; i != empIds.end(); i++) {
    int empId = *i;
    if (Employee* e = GpayrollDatabase.GetEmployee(empId)) {
      if (e->IsPayDate(itsPayDate)) {
	Paycheck* pc = new Paycheck(e->GetPayPeriodStartDate(itsPayDate),
				    itsPayDate);
	itsPaychecks[empId] = pc;
	e->Payday(*pc);
      }
    }
  }
}

Paycheck* PaydayTransaction::GetPaycheck(int empId)
{
  return itsPaychecks[empId];
}

int PaydayTransaction::GetPaycheckCount() const
{
  return itsPaychecks.size();
}
