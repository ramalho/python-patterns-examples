#ifndef NOAFFILIATION_H
#define NOAFFILIATION_H

#include "Affiliation.h"

class NoAffiliation : public Affiliation
{
 public:
  virtual ~NoAffiliation();
  NoAffiliation();
  virtual double CalculateDeductions(Paycheck&) const;
};

#endif
