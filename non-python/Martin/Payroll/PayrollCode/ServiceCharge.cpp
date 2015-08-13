#include "ServiceCharge.h"

ServiceCharge::~ServiceCharge()
{
}

ServiceCharge::ServiceCharge(const Date& date, double amount)
: itsDate(date)
, itsAmount(amount)
{
}
