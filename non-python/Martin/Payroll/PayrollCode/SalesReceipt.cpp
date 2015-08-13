#include "SalesReceipt.h"

SalesReceipt::~SalesReceipt()
{
}

SalesReceipt::SalesReceipt(const Date& saleDate, double amount)
: itsSaleDate(saleDate)
, itsAmount(amount)
{
}
