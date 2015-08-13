#ifndef SALESRECEIPT_H
#define SALESRECEIPT_H

#include "Date.h"

class SalesReceipt
{
 public:
  virtual ~SalesReceipt();
  SalesReceipt(const Date& saleDate, double amount);
  Date GetSaleDate() const {return itsSaleDate;}
  double GetAmount() const {return itsAmount;}
 private:
  Date itsSaleDate;
  double itsAmount;
};
#endif
