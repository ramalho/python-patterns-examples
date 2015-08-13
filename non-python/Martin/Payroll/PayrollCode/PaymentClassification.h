#ifndef PAYMENTCLASSIFICATION_H
#define PAYMENTCLASSIFICATION_H

class Paycheck;
#include "Date.h"

class PaymentClassification
{
 public:
  virtual ~PaymentClassification();

  virtual double CalculatePay(Paycheck&) const = 0;
 protected:

};
#endif
