#ifndef HOLDMETHOD_H
#define HOLDMETHOD_H

#include "PaymentMethod.h"

class HoldMethod : public PaymentMethod
{
 public:
  virtual ~HoldMethod();

  virtual void Pay(Paycheck&);
};
#endif
