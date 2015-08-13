#ifndef MONTHLYSCHEDULE_H
#define MONTHLYSCHEDULE_H

#include "PaymentSchedule.h"

class MonthlySchedule : public PaymentSchedule
{
 public:
  virtual ~MonthlySchedule();

  virtual bool IsPayDate(const Date&) const;
  virtual Date GetPayPeriodStartDate(const Date& payPeriodEndDate) const;
};
#endif
