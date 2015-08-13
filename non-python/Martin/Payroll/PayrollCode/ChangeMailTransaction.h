#ifndef CHANGEMAILTRANSACTION_H
#define CHANGEMAILTRANSACTION_H

#include "ChangeMethodTransaction.h"
#include <string>

class ChangeMailTransaction : public ChangeMethodTransaction
{
 public:
  virtual ~ChangeMailTransaction();
  ChangeMailTransaction(int empid, string address);
  virtual PaymentMethod* GetMethod() const;
 private:
  string itsAddress;
};

#endif
