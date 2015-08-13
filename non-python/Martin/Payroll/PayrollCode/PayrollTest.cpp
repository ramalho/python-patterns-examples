#include "PayrollTest.h"
#include "PayrollDatabase.h"
#include "AddSalariedEmployee.h"
#include "Employee.h"
#include "SalariedClassification.h"
#include "AddHourlyEmployee.h"
#include "MonthlySchedule.h"
#include "HoldMethod.h"
#include "HourlyClassification.h"
#include "WeeklySchedule.h"
#include "AddCommissionedEmployee.h"
#include "CommissionedClassification.h"
#include "BiweeklySchedule.h"
#include "DeleteEmployeeTransaction.h"
#include "TimeCardTransaction.h"
#include "TimeCard.h"
#include "SalesReceiptTransaction.h"
#include "SalesReceipt.h"
#include "UnionAffiliation.h"
#include "ServiceChargeTransaction.h"
#include "ServiceCharge.h"
#include "ChangeNameTransaction.h"
#include "ChangeAddressTransaction.h"
#include "ChangeHourlyTransaction.h"
#include "ChangeSalariedTransaction.h"
#include "ChangeCommissionedTransaction.h"
#include "ChangeMailTransaction.h"
#include "MailMethod.h"
#include "ChangeDirectTransaction.h"
#include "DirectMethod.h"
#include "ChangeHoldTransaction.h"
#include "ChangeMemberTransaction.h"
#include "ChangeUnaffiliatedTransaction.h"
#include "NoAffiliation.h"
#include "PaydayTransaction.h"
#include "Paycheck.h"

extern PayrollDatabase GpayrollDatabase;

void PayrollTest::setUp ()
{
  GpayrollDatabase.clear();
}

void PayrollTest::TestAddSalariedEmployee()
{
  cerr << "TestAddSalariedEmployee" << endl;
  int empId = 1;
  AddSalariedEmployee t(empId, "Bob", "Home", 1000.00);
  t.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  assert("Bob" == e->GetName());
  PaymentClassification* pc = e->GetClassification();
  SalariedClassification* sc = dynamic_cast<SalariedClassification*>(pc);
  assert(sc);
  assertEquals(1000.00, sc->GetSalary(), .001);
  PaymentSchedule* ps = e->GetSchedule();
  MonthlySchedule* ms = dynamic_cast<MonthlySchedule*>(ps);
  assert(ms);
  PaymentMethod* pm = e->GetMethod();
  HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);
  assert(hm);
}

void PayrollTest::TestAddHourlyEmployee()
{
  cerr << "TestAddHourlyEmployee" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  assert("Bill" == e->GetName());
  PaymentClassification* pc = e->GetClassification();
  HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
  assert(hc);
  assertEquals(15.25, hc->GetRate(), .001);
  PaymentSchedule* ps = e->GetSchedule();
  WeeklySchedule* ws = dynamic_cast<WeeklySchedule*>(ps);
  assert(ws);
  PaymentMethod* pm = e->GetMethod();
  HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);
  assert(hm);
}

void PayrollTest::TestAddCommissionedEmployee()
{
  cerr << "TestAddCommissionedEmployee" << endl;
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
  t.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  assert("Lance" == e->GetName());
  PaymentClassification* pc = e->GetClassification();
  CommissionedClassification* cc = dynamic_cast<CommissionedClassification*>(pc);
  assert(cc);
  assertEquals(2500, cc->GetSalary(), .001);
  PaymentSchedule* ps = e->GetSchedule();
  BiweeklySchedule* bws = dynamic_cast<BiweeklySchedule*>(ps);
  assert(bws);
  PaymentMethod* pm = e->GetMethod();
  HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);
  assert(hm);
}

void PayrollTest::TestDeleteEmployee()
{
  cerr << "TestDeleteEmployee" << endl;
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
  t.Execute();
  {
    Employee* e = GpayrollDatabase.GetEmployee(empId);
    assert(e);
  }
  DeleteEmployeeTransaction dt(empId);
  dt.Execute();
  {
    Employee* e = GpayrollDatabase.GetEmployee(empId);
    assert(e == 0);
  }
}

void PayrollTest::TestTimeCardTransaction()
{
  cerr << "TestTimeCardTransaction" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  TimeCardTransaction tct(Date(10,31,2001), 8.0, empId);
  tct.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  PaymentClassification* pc = e->GetClassification();
  HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
  assert(hc);
  TimeCard* tc = hc->GetTimeCard(Date(10,31,2001));
  assert(tc);
  assertEquals(8.0, tc->GetHours());
}

void PayrollTest::TestBadTimeCardTransaction()
{
  cerr << "TestBadTimeCardTransaction" << endl;
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
  t.Execute();
  TimeCardTransaction tct(Date(10,31,2001), 8.0, empId);
  try {
    tct.Execute();
    assert(false);
  }
  catch(const char* s) {
    cerr << "Caught: " << s << endl;
  }
}

void PayrollTest::TestSalesReceiptTransaction()
{
  cerr << "TestSalesReceiptTransaction" << endl;
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
  t.Execute();
  Date saleDate(11, 12, 2001); // Monday
  SalesReceiptTransaction srt(saleDate, 25000, empId);
  srt.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  PaymentClassification* pc = e->GetClassification();
  CommissionedClassification* cc = dynamic_cast<CommissionedClassification*>(pc);
  assert(cc);
  SalesReceipt* receipt = cc->GetReceipt(saleDate);
  assert(receipt);
  assertEquals(25000, receipt->GetAmount(), .001);
}

void PayrollTest::TestBadSalesReceiptTransaction()
{
  cerr << "TestBadSalesReceiptTransaction" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  Date saleDate(11,12,2001);
  SalesReceiptTransaction tct(saleDate, 25000, empId);
  try {
    tct.Execute();
    assert(false);
  }
  catch(const char* s) {
    cerr << "Caught: " << s << endl;
  }
}

void PayrollTest::TestAddServiceCharge()
{
  cerr << "TestAddServiceCharge" << endl;
  int empId = 2;
  int memberId = 86; // Maxwell Smart
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  UnionAffiliation* af = new UnionAffiliation(memberId, 12.5);
  e->SetAffiliation(af);
  GpayrollDatabase.AddUnionMember(memberId, e);
  Date serviceChargeDate(11,01,2001);
  ServiceChargeTransaction sct(memberId, serviceChargeDate, 12.95);
  sct.Execute();
  ServiceCharge* sc = af->GetServiceCharge(serviceChargeDate);
  assert(sc);
  assertEquals(12.95, sc->GetAmount(), .001);
}

void PayrollTest::TestChangeNameTransaction()
{
  cerr << "TestChangeNameTransaction" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  ChangeNameTransaction cnt(empId, "Bob");
  cnt.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  assert("Bob" == e->GetName());
}

void PayrollTest::TestChangeAddressTransaction()
{
  cerr << "TestChangeAddressTransaction" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  ChangeAddressTransaction cnt(empId, "PO Box 7575");
  cnt.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  assert("PO Box 7575" == e->GetAddress());
}

void PayrollTest::TestChangeHourlyTransaction()
{
  cerr << "TestChangeHourlyTransaction" << endl;
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
  t.Execute();
  ChangeHourlyTransaction cht(empId, 27.52);
  cht.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  PaymentClassification* pc = e->GetClassification();
  assert(pc);
  HourlyClassification* hc = dynamic_cast<HourlyClassification*>(pc);
  assert(hc);
  assertEquals(27.52, hc->GetRate(), .001);
  PaymentSchedule* ps = e->GetSchedule();
  WeeklySchedule* ws = dynamic_cast<WeeklySchedule*>(ps);
  assert(ws);
}

void PayrollTest::TestChangeSalariedTransaction()
{
  cerr << "TestChangeSalariedTransaction" << endl;
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
  t.Execute();
  ChangeSalariedTransaction cht(empId, 25000);
  cht.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  PaymentClassification* pc = e->GetClassification();
  assert(pc);
  SalariedClassification* sc = dynamic_cast<SalariedClassification*>(pc);
  assert(sc);
  assertEquals(25000, sc->GetSalary(), .001);
  PaymentSchedule* ps = e->GetSchedule();
  MonthlySchedule* ms = dynamic_cast<MonthlySchedule*>(ps);
  assert(ms);
}

void PayrollTest::TestChangeCommissionedTransaction()
{
  cerr << "TestChangeCommissionedTransaction" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  ChangeCommissionedTransaction cht(empId, 25000, 4.5);
  cht.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  PaymentClassification* pc = e->GetClassification();
  assert(pc);
  CommissionedClassification* cc = dynamic_cast<CommissionedClassification*>(pc);
  assert(cc);
  assertEquals(25000, cc->GetSalary(), .001);
  assertEquals(4.5, cc->GetRate(), .001);
  PaymentSchedule* ps = e->GetSchedule();
  BiweeklySchedule* bws = dynamic_cast<BiweeklySchedule*>(ps);
  assert(bws);
}

void PayrollTest::TestChangeMailTransaction()
{
  cerr << "TestChangeMailTransaction" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  ChangeMailTransaction cmt(empId, "4080 El Cerrito Road");
  cmt.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  PaymentMethod* pm = e->GetMethod();
  assert(pm);
  MailMethod* mm = dynamic_cast<MailMethod*>(pm);
  assert(mm);
  assert("4080 El Cerrito Road" == mm->GetAddress());
}

void PayrollTest::TestChangeDirectTransaction()
{
  cerr << "TestChangeDirectTransaction" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  ChangeDirectTransaction cdt(empId, "FirstNational", "1058209");
  cdt.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  PaymentMethod* pm = e->GetMethod();
  assert(pm);
  DirectMethod* dm = dynamic_cast<DirectMethod*>(pm);
  assert(dm);
  assert("FirstNational" == dm->GetBank());
  assert("1058209" == dm->GetAccount());
}

void PayrollTest::TestChangeHoldTransaction()
{
  cerr << "TestChangeHoldTransaction" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  ChangeDirectTransaction cdt(empId, "FirstNational", "1058209");
  cdt.Execute();
  ChangeHoldTransaction cht(empId);
  cht.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  PaymentMethod* pm = e->GetMethod();
  assert(pm);
  HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);
  assert(hm);
}

void PayrollTest::TestChangeMemberTransaction()
{
  cerr << "TestChangeMemberTransaction" << endl;
  int empId = 2;
  int memberId = 7734;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  ChangeMemberTransaction cmt(empId, memberId, 99.42);
  cmt.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  Affiliation* af = e->GetAffiliation();
  assert(af);
  UnionAffiliation* uf = dynamic_cast<UnionAffiliation*>(af);
  assert(uf);
  assertEquals(99.42, uf->GetDues(), .001);
  Employee* member = GpayrollDatabase.GetUnionMember(memberId);
  assert(member);
  assert(e == member);
}

void PayrollTest::TestChangeUnaffiliatedTransaction()
{
  cerr << "TestChangeUnaffiliatedTransaction" << endl;
  int empId = 2;
  int memberId = 7734;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  ChangeMemberTransaction cmt(empId, memberId, 99.42);
  cmt.Execute();
  ChangeUnaffiliatedTransaction cut(empId);
  cut.Execute();
  Employee* e = GpayrollDatabase.GetEmployee(empId);
  assert(e);
  Affiliation* af = e->GetAffiliation();
  assert(af);
  NoAffiliation* nf = dynamic_cast<NoAffiliation*>(af);
  assert(nf);
  Employee* member = GpayrollDatabase.GetUnionMember(memberId);
  assert(member == 0);
}

void PayrollTest::TestPaySingleSalariedEmployee()
{
  cerr << "TestPaySingleSalariedEmployee" << endl;
  int empId = 1;
  AddSalariedEmployee t(empId, "Bob", "Home", 1000.00);
  t.Execute();
  Date payDate(11,30,2001);
  PaydayTransaction pt(payDate);
  pt.Execute();
  ValidatePaycheck(pt, empId, payDate, 1000.00);
}

void PayrollTest::ValidatePaycheck(PaydayTransaction& pt,
				   int empid,
				   const Date& payDate,
				   double pay)
{
  Paycheck* pc = pt.GetPaycheck(empid);
  assert(pc);
  assert(pc->GetPayPeriodEndDate() == payDate);
  assertEquals(pay, pc->GetGrossPay(), .001);
  assert("Hold" == pc->GetField("Disposition"));
  assertEquals(0.0, pc->GetDeductions(), .001);
  assertEquals(pay, pc->GetNetPay(), .001);
}

void PayrollTest::TestPaySingleSalariedEmployeeOnWrongDate()
{
  cerr << "TestPaySingleSalariedEmployeeWrongDate" << endl;
  int empId = 1;
  AddSalariedEmployee t(empId, "Bob", "Home", 1000.00);
  t.Execute();
  Date payDate(11,29,2001);
  PaydayTransaction pt(payDate);
  pt.Execute();
  Paycheck* pc = pt.GetPaycheck(empId);
  assert(pc == 0);
}

void PayrollTest::TestPayMultipleSalariedEmployees()
{
  cerr << "TestPayMultipleSalariedEmployees" << endl;
  AddSalariedEmployee t1(1, "Bob", "Home", 1000.00);
  AddSalariedEmployee t2(2, "Bill", "Home", 2000.00);
  AddSalariedEmployee t3(3, "Barry", "Home", 3000.00);
  t1.Execute();
  t2.Execute();
  t3.Execute();
  Date payDate(11,30,2001);
  PaydayTransaction pt(payDate);
  pt.Execute();
  assertEquals(3L, pt.GetPaycheckCount());
  ValidatePaycheck(pt, 1, payDate, 1000.00);
  ValidatePaycheck(pt, 2, payDate, 2000.00);
  ValidatePaycheck(pt, 3, payDate, 3000.00);
}

void PayrollTest::TestPaySingleHourlyEmployeeNoTimeCards()
{
  cerr << "TestPaySingleHourlyEmployeeNoTimeCards" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  Date payDate(11,9,2001); // Friday
  PaydayTransaction pt(payDate);
  pt.Execute();
  ValidatePaycheck(pt, empId, payDate, 0.0);
}

void PayrollTest::TestPaySingleHourlyEmployeeOneTimeCard()
{
  cerr << "TestPaySingleHourlyEmployeeOneTimeCard" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  Date payDate(11,9,2001); // Friday

  TimeCardTransaction tc(payDate, 2.0, empId);
  tc.Execute();
  PaydayTransaction pt(payDate);
  pt.Execute();
  ValidatePaycheck(pt, empId, payDate, 30.5);
}

void PayrollTest::TestPaySingleHourlyEmployeeOvertimeOneTimeCard()
{
  cerr << "TestPaySingleHourlyEmployeeOvertimeOneTimeCard" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  Date payDate(11,9,2001); // Friday

  TimeCardTransaction tc(payDate, 9.0, empId);
  tc.Execute();
  PaydayTransaction pt(payDate);
  pt.Execute();
  ValidatePaycheck(pt, empId, payDate, (8 + 1.5) * 15.25);
}

void PayrollTest::TestPaySingleHourlyEmployeeOnWrongDate()
{
  cerr << "TestPaySingleHourlyEmployeeOnWrongDate" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  Date payDate(11,8,2001); // Thursday

  TimeCardTransaction tc(payDate, 9.0, empId);
  tc.Execute();
  PaydayTransaction pt(payDate);
  pt.Execute();

  Paycheck* pc = pt.GetPaycheck(empId);
  assert(pc == 0);
}

void PayrollTest::TestPaySingleHourlyEmployeeTwoTimeCards()
{
  cerr << "TestPaySingleHourlyEmployeeTwoTimeCards" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  Date payDate(11,9,2001); // Friday

  TimeCardTransaction tc(payDate, 2.0, empId);
  tc.Execute();
  TimeCardTransaction tc2(Date(11,8,2001), 5.0, empId);
  tc2.Execute();
  PaydayTransaction pt(payDate);
  pt.Execute();
  ValidatePaycheck(pt, empId, payDate, 7*15.25);
}

void PayrollTest::TestPaySingleHourlyEmployeeWithTimeCardsSpanningTwoPayPeriods()
{
  cerr << "TestPaySingleHourlyEmployeeWithTimeCardsSpanningTwoPayPeriods" << endl;
  int empId = 2;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();
  Date payDate(11,9,2001); // Friday
  Date dateInPreviousPayPeriod(11,2,2001);

  TimeCardTransaction tc(payDate, 2.0, empId);
  tc.Execute();
  TimeCardTransaction tc2(dateInPreviousPayPeriod, 5.0, empId);
  tc2.Execute();
  PaydayTransaction pt(payDate);
  pt.Execute();
  ValidatePaycheck(pt, empId, payDate, 2*15.25);
}

void PayrollTest::TestPaySingleCommissionedEmployeeNoSalesReceipts()
{
  cerr << "TestPaySingleCommissionedEmployeeNoSalesReceipts" << endl;
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
  t.Execute();
  Date payDate(11,9,2001); // Friday
  PaydayTransaction pt(payDate);
  pt.Execute();
  ValidatePaycheck(pt, empId, payDate, 2500.00);
}

void PayrollTest::TestPaySingleCommissionedEmployeeOneSalesReceipt()
{
  cerr << "TestPaySingleCOmmissionedEmployeeOneSalesReciept" << endl;
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, .032);
  t.Execute();
  Date payDate(11,9,2001); // Friday
  SalesReceiptTransaction srt(payDate, 13000.00, empId);
  srt.Execute();
  PaydayTransaction pt(payDate);
  pt.Execute();
  ValidatePaycheck(pt, empId, payDate, 2500.00 + .032 * 13000);
}

void PayrollTest::TestPaySingleCommissionedEmployeeTwoSalesReceipts()
{
  cerr << "TestPaySingleCommissionedEmployeeTwoSalesReceipts" << endl;
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, .032);
  t.Execute();
  Date payDate(11,9,2001); // Biweekly Friday
  SalesReceiptTransaction srt(payDate, 13000.00, empId);
  srt.Execute();
  SalesReceiptTransaction srt2(Date(11,8,2001), 24000, empId);
  srt2.Execute();
  PaydayTransaction pt(payDate);
  pt.Execute();
  ValidatePaycheck(pt, empId, payDate, 2500.00 + .032 * 13000 + .032 * 24000);
}

void PayrollTest::TestPaySingleCommissionedEmployeeWrongDate()
{
  cerr << "TestPaySingleCommissionedEmployeeWrongDate" << endl;
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, .032);
  t.Execute();
  Date payDate(11,16,2001); // Wrong Friday
  SalesReceiptTransaction srt(payDate, 13000.00, empId);
  srt.Execute();
  SalesReceiptTransaction srt2(Date(11,15,2001), 24000, empId);
  srt2.Execute();
  PaydayTransaction pt(payDate);
  pt.Execute();

  Paycheck* pc = pt.GetPaycheck(empId);
  assert(pc == 0);
}

void PayrollTest::TestPaySingleCommissionedEmployeeSpanMultiplePayPeriods()
{
  cerr << "TestPaySingleCommissionedEmployeeSpanMultiplePayPeriods" << endl;
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, .032);
  t.Execute();
  Date earlyDate(11,9,2001); // Previous pay period
  Date payDate(11,23,2001); // Biweekly Friday
  Date lateDate(12,7,2001); // Next pay period.
  SalesReceiptTransaction srt(payDate, 13000.00, empId);
  srt.Execute();
  SalesReceiptTransaction srt2(earlyDate, 24000, empId);
  srt2.Execute();
  SalesReceiptTransaction srt3(lateDate, 15000, empId);
  srt3.Execute();
  PaydayTransaction pt(payDate);
  pt.Execute();
  ValidatePaycheck(pt, empId, payDate, 2500.00 + .032 * 13000);
}

void PayrollTest::TestSalariedUnionMemberDues()
{
  cerr << "TestSalariedUnionMemberDues" << endl;
  int empId = 1;
  AddSalariedEmployee t(empId, "Bob", "Home", 1000.00);
  t.Execute();
  int memberId = 7734;
  ChangeMemberTransaction cmt(empId, memberId, 9.42);
  cmt.Execute();
  Date payDate(11,30,2001);
  int fridays = 5; // Fridays in Nov, 2001.
  PaydayTransaction pt(payDate);
  pt.Execute();
  Paycheck* pc = pt.GetPaycheck(empId);
  assert(pc);
  assert(pc->GetPayPeriodEndDate() == payDate);
  assertEquals(1000.00, pc->GetGrossPay(), .001);
  assert("Hold" == pc->GetField("Disposition"));
  assertEquals(fridays*9.42, pc->GetDeductions(), .001);
  assertEquals(1000.0 - (fridays * 9.42), pc->GetNetPay(), .001);
}

void PayrollTest::TestHourlyUnionMemberDues()
{
  cerr << "TestHourlyUnionMemberDues" << endl;
  int empId = 1;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.24);
  t.Execute();
  int memberId = 7734;
  ChangeMemberTransaction cmt(empId, memberId, 9.42);
  cmt.Execute();
  Date payDate(11,9,2001);
  TimeCardTransaction tct(payDate, 8.0, empId);
  tct.Execute();
  PaydayTransaction pt(payDate);
  pt.Execute();
  Paycheck* pc = pt.GetPaycheck(empId);
  assert(pc);
  assert(pc->GetPayPeriodEndDate() == payDate);
  assertEquals(8*15.24, pc->GetGrossPay(), .001);
  assert("Hold" == pc->GetField("Disposition"));
  assertEquals(9.42, pc->GetDeductions(), .001);
  assertEquals((8*15.24)-9.42, pc->GetNetPay(), .001);
}

void PayrollTest::TestCommissionedUnionMemberDues()
{
  cerr << "TestCommissionedUnionMemberDues" << endl;
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, .032);
  t.Execute();
  int memberId = 7734;
  ChangeMemberTransaction cmt(empId, memberId, 9.42);
  cmt.Execute();
  Date payDate(11,9,2001);
  PaydayTransaction pt(payDate);
  pt.Execute();
  Paycheck* pc = pt.GetPaycheck(empId);
  assert(pc);
  assert(pc->GetPayPeriodEndDate() == payDate);
  assertEquals(2500.00, pc->GetGrossPay(), .001);
  assert("Hold" == pc->GetField("Disposition"));
  assertEquals(2*9.42, pc->GetDeductions(), .001);
  assertEquals(2500.0 - (2 * 9.42), pc->GetNetPay(), .001);
}

void PayrollTest::TestHourlyUnionMemberServiceCharge()
{
  cerr << "TestHourlyUnionMemberServiceCharge" << endl;
  int empId = 1;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.24);
  t.Execute();
  int memberId = 7734;
  ChangeMemberTransaction cmt(empId, memberId, 9.42);
  cmt.Execute();
  Date payDate(11,9,2001);
  ServiceChargeTransaction sct(memberId, payDate, 19.42);
  sct.Execute();
  TimeCardTransaction tct(payDate, 8.0, empId);
  tct.Execute();
  PaydayTransaction pt(payDate);
  pt.Execute();
  Paycheck* pc = pt.GetPaycheck(empId);
  assert(pc);
  assert(pc->GetPayPeriodEndDate() == payDate);
  assertEquals(8*15.24, pc->GetGrossPay(), .001);
  assert("Hold" == pc->GetField("Disposition"));
  assertEquals(9.42 + 19.42, pc->GetDeductions(), .001);
  assertEquals((8*15.24)-(9.42 + 19.42), pc->GetNetPay(), .001);
}

void PayrollTest::TestServiceChargesSpanningMultiplePayPeriods()
{
  cerr << "TestServiceChargesSpanningMultiplePayPeriods" << endl;
  int empId = 1;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.24);
  t.Execute();
  int memberId = 7734;
  ChangeMemberTransaction cmt(empId, memberId, 9.42);
  cmt.Execute();
  Date earlyDate(11,2,2001); // previous Friday
  Date payDate(11,9,2001);
  Date lateDate(11,16,2001); // next Friday
  ServiceChargeTransaction sct(memberId, payDate, 19.42);
  sct.Execute();
  ServiceChargeTransaction sctEarly(memberId, earlyDate, 100.00);
  sctEarly.Execute();
  ServiceChargeTransaction sctLate(memberId, lateDate, 200.00);
  sctLate.Execute();
  TimeCardTransaction tct(payDate, 8.0, empId);
  tct.Execute();
  PaydayTransaction pt(payDate);
  pt.Execute();
  Paycheck* pc = pt.GetPaycheck(empId);
  assert(pc);
  assert(pc->GetPayPeriodEndDate() == payDate);
  assertEquals(8*15.24, pc->GetGrossPay(), .001);
  assert("Hold" == pc->GetField("Disposition"));
  assertEquals(9.42 + 19.42, pc->GetDeductions(), .001);
  assertEquals((8*15.24)-(9.42 + 19.42), pc->GetNetPay(), .001);
}

//------------------------------------------
template <class T>
TestCaller<T>* makeTestCaller(char* name, void (T::*f)() )
{
  return new TestCaller<T>(name, f);
}

#define ADDTEST(NAME)  testSuite->addTest (makeTestCaller("NAME", &PayrollTest::NAME));

Test *PayrollTest::suite ()
{
  TestSuite *testSuite = new TestSuite ("PayrollTest");
  ADDTEST(TestAddSalariedEmployee);
  ADDTEST(TestAddHourlyEmployee);
  ADDTEST(TestAddCommissionedEmployee);
  ADDTEST(TestDeleteEmployee);
  ADDTEST(TestTimeCardTransaction);
  ADDTEST(TestBadTimeCardTransaction);
  ADDTEST(TestSalesReceiptTransaction);
  ADDTEST(TestBadSalesReceiptTransaction);
  ADDTEST(TestAddServiceCharge);
  ADDTEST(TestChangeNameTransaction);
  ADDTEST(TestChangeAddressTransaction);
  ADDTEST(TestChangeHourlyTransaction);
  ADDTEST(TestChangeSalariedTransaction);
  ADDTEST(TestChangeCommissionedTransaction);
  ADDTEST(TestChangeMailTransaction);
  ADDTEST(TestChangeDirectTransaction);
  ADDTEST(TestChangeHoldTransaction);
  ADDTEST(TestChangeMemberTransaction);
  ADDTEST(TestChangeUnaffiliatedTransaction);
  ADDTEST(TestPaySingleSalariedEmployee);
  ADDTEST(TestPaySingleSalariedEmployeeOnWrongDate);
  ADDTEST(TestPayMultipleSalariedEmployees);
  ADDTEST(TestPaySingleHourlyEmployeeNoTimeCards);
  ADDTEST(TestPaySingleHourlyEmployeeOneTimeCard);
  ADDTEST(TestPaySingleHourlyEmployeeOvertimeOneTimeCard);
  ADDTEST(TestPaySingleHourlyEmployeeOnWrongDate);
  ADDTEST(TestPaySingleHourlyEmployeeTwoTimeCards);
  ADDTEST(TestPaySingleHourlyEmployeeWithTimeCardsSpanningTwoPayPeriods);
  ADDTEST(TestPaySingleCommissionedEmployeeNoSalesReceipts);
  ADDTEST(TestPaySingleCommissionedEmployeeOneSalesReceipt);
  ADDTEST(TestPaySingleCommissionedEmployeeTwoSalesReceipts);
  ADDTEST(TestPaySingleCommissionedEmployeeWrongDate);
  ADDTEST(TestPaySingleCommissionedEmployeeSpanMultiplePayPeriods);
  ADDTEST(TestSalariedUnionMemberDues);
  ADDTEST(TestHourlyUnionMemberDues);
  ADDTEST(TestCommissionedUnionMemberDues);
  ADDTEST(TestHourlyUnionMemberServiceCharge);
  ADDTEST(TestServiceChargesSpanningMultiplePayPeriods);
  return testSuite;
}

