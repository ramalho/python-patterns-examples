#ifndef UNIONAFFILIATION_H
#define UNIONAFFILIATION_H

#include "Affiliation.h"
#include "Date.h"

#include <map>

class ServiceCharge;

class UnionAffiliation : public Affiliation
{
 public:
  virtual ~UnionAffiliation();
  UnionAffiliation(int memberId, double dues);
  void AddServiceCharge(const Date& date, double amount);
  ServiceCharge* GetServiceCharge(const Date& date);
  double GetDues() const {return itsDues;}
  int GetMemberId() const {return itsMemberId;}
  virtual double CalculateDeductions(Paycheck&) const;

 private:
  int itsMemberId;
  double itsDues;
  map<Date, ServiceCharge*> itsServiceCharges;
};
#endif
