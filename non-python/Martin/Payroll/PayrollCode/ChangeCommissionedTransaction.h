#ifndef CHANGECOMMMISSIONEDTRANSACTION_H
#define CHANGECOMMISSIONEDTRANSACTION_H

#include "ChangeClassificationTransaction.h"

class ChangeCommissionedTransaction : public ChangeClassificationTransaction
{
 public:
  virtual ~ChangeCommissionedTransaction();
  ChangeCommissionedTransaction(int empid, double salary, double rate);
  virtual PaymentSchedule* GetSchedule() const;
  virtual PaymentClassification* GetClassification() const;

 private:
  double itsSalary;
  double itsRate;
};

#endif
