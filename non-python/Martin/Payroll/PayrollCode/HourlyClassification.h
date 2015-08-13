#ifndef HOURLYCLASSIFICATION_H
#define HOURLYCLASSIFICATION_H

#include <map>

#include "PaymentClassification.h"
#include "Date.h"

class TimeCard;

class HourlyClassification : public PaymentClassification
{
 public:
  virtual ~HourlyClassification();
  HourlyClassification(double hourlyRate);
  double GetRate() const {return itsRate;}

  void AddTimeCard(TimeCard* tc);
  TimeCard* GetTimeCard(const Date& date);

  virtual double CalculatePay(Paycheck&) const;

 private:
  double CalculatePayForTimeCard(TimeCard*) const;

 private:
  double itsRate;
  map<Date, TimeCard*> itsTimeCards;

};

#endif
