#ifndef SERVICECHARGETRANSACTION_H
#define SERVICECHARGETRANSACTION_H

#include "Transaction.h"
#include "Date.h"

class ServiceChargeTransaction : public Transaction
{
 public:
  virtual ~ServiceChargeTransaction();
  ServiceChargeTransaction(int memberId, const Date& date, double charge);
  virtual void Execute();

 private:
  int itsMemberId;
  Date itsDate;
  double itsCharge;
};
#endif
