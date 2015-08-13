#ifndef SALESRECEIPTTRANSACTION_H
#define SALESRECEIPTTRANSACTION_H

#include "Transaction.h"
#include "Date.h"

class SalesReceiptTransaction : public Transaction
{
 public:
  virtual ~SalesReceiptTransaction();
  SalesReceiptTransaction(const Date& saleDate, double amount, int empid);

  virtual void Execute();

 private:
  int itsEmpid;
  Date itsSaleDate;
  double itsAmount;
};
#endif
