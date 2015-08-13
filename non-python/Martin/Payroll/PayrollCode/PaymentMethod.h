#ifndef PAYMENTMETHOD_H
#define PAYMENTMETHOD_H

class Paycheck;

class PaymentMethod
{
 public:
  virtual ~PaymentMethod();

  virtual void Pay(Paycheck&) = 0;
};
#endif
