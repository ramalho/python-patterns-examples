#ifndef SALARIEDCLASSIFICATION_H
#define SALARIEDCLASSIFICATION_H

#include "PaymentClassification.h"

class SalariedClassification : public PaymentClassification
{
 public:
  virtual ~SalariedClassification();
  SalariedClassification(double salary);
  double GetSalary() const;

  virtual double CalculatePay(Paycheck&) const;

 private:
  double itsSalary;
};
#endif
