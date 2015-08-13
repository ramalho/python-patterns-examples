#ifndef PAYMENTSCHEDULE_H
#define PAYMENTSCHEDULE_H

class Date;

class PaymentSchedule
{
 public:
  virtual ~PaymentSchedule();

  virtual bool IsPayDate(const Date&) const = 0;
  virtual Date GetPayPeriodStartDate(const Date& payPeriodEndDate) const = 0;
};
#endif
