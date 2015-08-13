#ifndef PAYROLLDATABASE_H
#define PAYROLLDATABASE_H

#include <map>
#include <list>

class Employee;

class PayrollDatabase
{
 public:
  virtual ~PayrollDatabase();
  Employee* GetEmployee(int empId);
  void AddEmployee(int empid, Employee*);
  void DeleteEmployee(int empid);
  void AddUnionMember(int memberId, Employee*);
  Employee* GetUnionMember(int memberId);
  void RemoveUnionMember(int memberId);
  void clear(); 
  void GetAllEmployeeIds(list<int>&);

 private:
  map<int, Employee*> itsEmployees;
  map<int, int> itsUnionMembers;
};

#endif

