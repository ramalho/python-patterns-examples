#include "TimeCard.h"

TimeCard::~TimeCard()
{
}

TimeCard::TimeCard(const Date& date, double hours)
: itsDate(date)
, itsHours(hours)
{
}
