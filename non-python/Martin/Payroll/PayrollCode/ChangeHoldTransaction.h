#ifndef CHANGEHOLDTRANSACTION_H
#define CHANGEHOLDTRANSACTION_H

#include "ChangeMethodTransaction.h"

class ChangeHoldTransaction : public ChangeMethodTransaction
{
 public:
  virtual ~ChangeHoldTransaction();
  ChangeHoldTransaction(int empid);
  virtual PaymentMethod* GetMethod() const;
};
#endif
