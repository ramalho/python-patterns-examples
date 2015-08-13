#ifndef PAYDAYTRANSACTION_H
#define PAYDAYTRANSACTION_H

#include "Transaction.h"
#include "Date.h"

#include <map>

class Paycheck;

class PaydayTransaction : public Transaction
{
 public:
  virtual ~PaydayTransaction();
  PaydayTransaction(Date payDate);
  virtual void Execute();
  Paycheck* GetPaycheck(int empId);
  int GetPaycheckCount() const;

 private:
  Date itsPayDate;
  map<int, Paycheck*> itsPaychecks;
};

#endif
