#include "PayrollDatabase.h"
#include "Employee.h"

PayrollDatabase GpayrollDatabase;

PayrollDatabase::~PayrollDatabase()
{
}

Employee* PayrollDatabase::GetEmployee(int empid)
{
  return itsEmployees[empid];
}

void PayrollDatabase::AddEmployee(int empid, Employee* e)
{
  itsEmployees[empid] = e;
}

void PayrollDatabase::DeleteEmployee(int empid)
{
  itsEmployees.erase(empid);
}

void PayrollDatabase::AddUnionMember(int memberId, Employee* emp)
{
  itsUnionMembers[memberId] = emp->GetEmpid();
}

void PayrollDatabase::clear()
{
  itsEmployees.clear();
  itsUnionMembers.clear();
}

Employee* PayrollDatabase::GetUnionMember(int memberId)
{
  int empId = itsUnionMembers[memberId];
  Employee* e = itsEmployees[empId];
  return e;
}

void PayrollDatabase::RemoveUnionMember(int memberId)
{
  itsUnionMembers.erase(memberId);
}

void PayrollDatabase::GetAllEmployeeIds(list<int>& empIds)
{
  empIds.clear();
  map<int, Employee*>::iterator i = itsEmployees.begin();
  for (; i != itsEmployees.end(); i++) {
    empIds.push_back((*i).first);
  }
}


