#include "BiweeklySchedule.h"
#include "Date.h"

BiweeklySchedule::~BiweeklySchedule()
{
}

bool BiweeklySchedule::IsPayDate(const Date& theDate) const
{
  Date firstPayableFriday(11,9,2001);
  int daysSinceFirstPayableFriday = theDate - firstPayableFriday;
  return (daysSinceFirstPayableFriday % 14) == 0; //  two weeks.
}

Date BiweeklySchedule::GetPayPeriodStartDate(const Date& payPeriodEndDate) const
{
  return payPeriodEndDate - 13; // Saturday, two weeks ago.
}

