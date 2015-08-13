#ifndef AFFILIATION_H
#define AFFILIATION_H

class Paycheck;

class Affiliation
{
 public:
  virtual ~Affiliation();
  Affiliation();

  virtual double CalculateDeductions(Paycheck&) const = 0;
};

#endif
