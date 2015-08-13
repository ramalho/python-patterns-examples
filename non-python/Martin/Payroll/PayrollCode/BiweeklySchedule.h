#ifndef BIWEEKLYSCHEDULE_H
#define BIWEEKLYSCHEDULE_H

#include "PaymentSchedule.h"

class BiweeklySchedule : public PaymentSchedule
{
 public:
  ~BiweeklySchedule();
  virtual bool IsPayDate(const Date&) const;
  virtual Date GetPayPeriodStartDate(const Date& payPeriodEndDate) const;
};
#endif
