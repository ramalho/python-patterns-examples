#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class PaymentSchedule;
class PaymentClassification;
class PaymentMethod;
class Affiliation;
class Paycheck;
class Date;

class Employee
{
 public:
  virtual ~Employee();
  Employee(int empid, string name, string address);
  void SetName(string name);
  void SetAddress(string address);
  void SetClassification(PaymentClassification*);
  void SetMethod(PaymentMethod*);
  void SetSchedule(PaymentSchedule*);
  void SetAffiliation(Affiliation*);

  int GetEmpid() const {return itsEmpid;}
  string GetName() const {return itsName;}
  string GetAddress() const {return itsAddress;}
  PaymentMethod* GetMethod() {return itsPaymentMethod;}
  PaymentClassification* GetClassification() {return itsClassification;}
  PaymentSchedule* GetSchedule() {return itsSchedule;}
  Affiliation* GetAffiliation() {return itsAffiliation;}

  void Payday(Paycheck&);
  bool IsPayDate(const Date& payDate) const;
  Date GetPayPeriodStartDate(const Date& payPeriodEndDate) const;

 private:
  int itsEmpid;
  string itsName;
  string itsAddress;
  PaymentClassification* itsClassification;
  PaymentSchedule* itsSchedule;
  PaymentMethod* itsPaymentMethod;
  Affiliation* itsAffiliation;
};

#endif
