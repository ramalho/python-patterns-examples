#include "SalesReceiptTransaction.h"
#include "Employee.h"
#include "PayrollDatabase.h"
#include "CommissionedClassification.h"
#include "SalesReceipt.h"

extern PayrollDatabase GpayrollDatabase;

SalesReceiptTransaction::~SalesReceiptTransaction()
{
}

SalesReceiptTransaction::SalesReceiptTransaction(const Date& saleDate, double amount, int empid)
: itsSaleDate(saleDate)
, itsAmount(amount)
, itsEmpid(empid)
{
}

void SalesReceiptTransaction::Execute()
{
  Employee* e = GpayrollDatabase.GetEmployee(itsEmpid);
  if (e){
    PaymentClassification* pc = e->GetClassification();
    if (CommissionedClassification* cc = dynamic_cast<CommissionedClassification*>(pc)) {
      cc->AddReceipt(new SalesReceipt(itsSaleDate, itsAmount));
    } else
      throw("Tried to add sales receipt to non-commissioned employee");
  } else
    throw("No such employee.");
}
