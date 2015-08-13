#include "SalariedClassification.h"

SalariedClassification::~SalariedClassification()
{
}

SalariedClassification::SalariedClassification(double salary)
  :itsSalary(salary)
{
}

double SalariedClassification::GetSalary() const
{
  return itsSalary;
}

double SalariedClassification::CalculatePay(Paycheck&) const
{
  return itsSalary;
}
