
#ifndef CPP_UNIT_PAYROLLTEST_H
#define CPP_UNIT_PAYROLLTEST_H

#include "TestCase.h"
#include "TestSuite.h"
#include "TestCaller.h"

class PaydayTransaction;
class Date;

class PayrollTest: public TestCase
{
 public:
  PayrollTest (std::string name) : TestCase (name) {}

  void			setUp ();
  static Test		*suite ();

 protected:
  void TestAddSalariedEmployee();
  void TestAddHourlyEmployee();
  void TestAddCommissionedEmployee();
  void TestDeleteEmployee();
  void TestTimeCardTransaction();
  void TestBadTimeCardTransaction();
  void TestSalesReceiptTransaction();
  void TestBadSalesReceiptTransaction();
  void TestAddServiceCharge();
  void TestChangeNameTransaction();
  void TestChangeAddressTransaction();
  void TestChangeHourlyTransaction();
  void TestChangeSalariedTransaction();
  void TestChangeCommissionedTransaction();
  void TestChangeMailTransaction();
  void TestChangeDirectTransaction();
  void TestChangeHoldTransaction();
  void TestChangeMemberTransaction();
  void TestChangeUnaffiliatedTransaction();
  void TestPaySingleSalariedEmployee();
  void TestPaySingleSalariedEmployeeOnWrongDate();
  void TestPayMultipleSalariedEmployees();
  void TestPaySingleHourlyEmployeeNoTimeCards();
  void TestPaySingleHourlyEmployeeOneTimeCard();
  void TestPaySingleHourlyEmployeeOvertimeOneTimeCard();
  void TestPaySingleHourlyEmployeeOnWrongDate();
  void TestPaySingleHourlyEmployeeTwoTimeCards();
  void TestPaySingleHourlyEmployeeWithTimeCardsSpanningTwoPayPeriods();
  void TestPaySingleCommissionedEmployeeNoSalesReceipts();
  void TestPaySingleCommissionedEmployeeOneSalesReceipt();
  void TestPaySingleCommissionedEmployeeTwoSalesReceipts();
  void TestPaySingleCommissionedEmployeeWrongDate();
  void TestPaySingleCommissionedEmployeeSpanMultiplePayPeriods();
  void TestSalariedUnionMemberDues();
  void TestHourlyUnionMemberDues();
  void TestCommissionedUnionMemberDues();
  void TestHourlyUnionMemberServiceCharge();
  void TestServiceChargesSpanningMultiplePayPeriods();
 private:
  void ValidatePaycheck(PaydayTransaction& pt, 
			int empid, 
			const Date& payDate, 
			double pay);

};


#endif
