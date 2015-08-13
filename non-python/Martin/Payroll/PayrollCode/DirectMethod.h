#ifndef DIRECTMETHOD_H
#define DIRECTMETHOD_H

#include "PaymentMethod.h"
#include <string>

class DirectMethod : public PaymentMethod
{
 public:
  virtual ~DirectMethod();
  DirectMethod(string bank, string account);
  string GetBank() {return itsBank;}
  string GetAccount() {return itsAccount;}

  virtual void Pay(Paycheck&);

 private:
  string itsBank;
  string itsAccount;
};
#endif
