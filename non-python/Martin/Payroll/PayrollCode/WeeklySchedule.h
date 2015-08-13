#ifndef WEEKLYSCHEDULE_H
#define WEEKLYSCHEDULE_H

#include "PaymentSchedule.h"

class WeeklySchedule : public PaymentSchedule
{
 public:
  ~WeeklySchedule();
  virtual bool IsPayDate(const Date&) const;
  virtual Date GetPayPeriodStartDate(const Date& payPeriodEndDate) const;
};
#endif
