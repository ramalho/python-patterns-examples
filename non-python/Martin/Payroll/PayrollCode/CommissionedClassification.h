#ifndef COMMISSIONEDCLASSIFICATION_H
#define COMMISSIONEDCLASSIFICATION_H

#include <map>

#include "PaymentClassification.h"
#include "Date.h"
class SalesReceipt;

class CommissionedClassification : public PaymentClassification
{
 public:
  virtual ~CommissionedClassification();
  CommissionedClassification(double salary, double commissionRate);
  double GetSalary() const;
  double GetRate() const;

  SalesReceipt* GetReceipt(const Date& saleDate);
  void AddReceipt(SalesReceipt*);

  virtual double CalculatePay(Paycheck&) const;

 private:
  double itsSalary;
  double itsCommissionRate;
  map<Date, SalesReceipt*> itsReceipts;
};
#endif
