#ifndef TIMECARD_H
#define TIMECARD_H

#include "Date.h"

class TimeCard
{
 public:
  virtual ~TimeCard();
  TimeCard(const Date& date, double hours);
  Date GetDate() {return itsDate;}
  double GetHours() {return itsHours;}
 private:
  Date itsDate;
  double itsHours;
};
#endif
