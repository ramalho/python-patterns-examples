#ifndef CHANGEADDRESSTRANSACTION_H
#define CHANGEADDRESSTRANSACTION_H

#include "ChangeEmployeeTransaction.h"
#include <string>

class ChangeAddressTransaction : public ChangeEmployeeTransaction
{
 public:
  virtual ~ChangeAddressTransaction();
  ChangeAddressTransaction(int empid, string address);
  virtual void Change(Employee& e);

 private:
  string itsAddress;
};

#endif
