#include "MonthlySchedule.h"
#include "Date.h"

MonthlySchedule::~MonthlySchedule()
{
}

namespace
{
  bool IsLastDayOfMonth(const Date& date)
  {
    int m1 = date.GetMonth();
    int m2 = (date+1).GetMonth();
    return (m1 != m2);
  }
}

bool MonthlySchedule::IsPayDate(const Date& payDate) const
{
  return IsLastDayOfMonth(payDate);
}

Date MonthlySchedule::GetPayPeriodStartDate(const Date& payPeriodEndDate) const
{
  int lastDayOfMonth = payPeriodEndDate.GetDay();
  Date firstDayOfMonth = payPeriodEndDate - (lastDayOfMonth - 1);
  return firstDayOfMonth;
}

