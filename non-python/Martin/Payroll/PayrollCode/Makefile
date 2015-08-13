LDLIBS = -lstdc++ -lframework -ltextui
clean:	
	rm -f *.o


DOTO =  Transaction.o ChangeEmployeeTransaction.o PayrollDatabase.o \
	Employee.o ChangeNameTransaction.o ChangeAddressTransaction.o \
	ChangeClassificationTransaction.o PaymentClassification.o \
	PaymentSchedule.o HourlyClassification.o WeeklySchedule.o \
	ChangeHourlyTransaction.o AddEmployeeTransaction.o \
	PaymentMethod.o HoldMethod.o AddSalariedEmployee.o \
	SalariedClassification.o MonthlySchedule.o AddHourlyEmployee.o \
	AddCommissionedEmployee.o BiweeklySchedule.o CommissionedClassification.o \
	DeleteEmployeeTransaction.o TimeCardTransaction.o TimeCard.o \
	SalesReceiptTransaction.o SalesReceipt.o Affiliation.o UnionAffiliation.o \
	NoAffiliation.o ServiceChargeTransaction.o ServiceCharge.o \
	ChangeSalariedTransaction.o ChangeCommissionedTransaction.o \
	ChangeMethodTransaction.o ChangeMailTransaction.o MailMethod.o \
	ChangeDirectTransaction.o DirectMethod.o ChangeHoldTransaction.o \
	ChangeAffiliationTransaction.o ChangeMemberTransaction.o \
	ChangeUnaffiliatedTransaction.o Date.o PaydayTransaction.o Paycheck.o

all: 	clean $(DOTO)

CPPFLAGS = -I "cppunit1.5\CppUnit\test\framework" -I "cppunit1.5\cppunit\test\textui"
LDFLAGS = -L "cppunit1.5\CppUnit\test\framework" -L "cppunit1.5\CppUnit\test\textui"

TestRunner : TestRunner.o PayrollTest.o $(DOTO)
	$(CC) -o TestRunner $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS)

depend : 
	gcc -MM ${CPPFLAGS} *.cpp

test : TestRunner
	./TestRunner PayrollTest

datetest : datetest.o Date.o
	$(CC) -o datetest $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS)
	./datetest

AddCommissionedEmployee.o: AddCommissionedEmployee.cpp \
 AddCommissionedEmployee.h AddEmployeeTransaction.h Transaction.h \
 CommissionedClassification.h PaymentClassification.h Date.h \
 BiweeklySchedule.h PaymentSchedule.h
AddEmployeeTransaction.o: AddEmployeeTransaction.cpp \
 AddEmployeeTransaction.h Transaction.h HoldMethod.h PaymentMethod.h \
 Employee.h PayrollDatabase.h
AddHourlyEmployee.o: AddHourlyEmployee.cpp AddHourlyEmployee.h \
 AddEmployeeTransaction.h Transaction.h HourlyClassification.h \
 PaymentClassification.h Date.h WeeklySchedule.h PaymentSchedule.h
AddSalariedEmployee.o: AddSalariedEmployee.cpp AddSalariedEmployee.h \
 AddEmployeeTransaction.h Transaction.h SalariedClassification.h \
 PaymentClassification.h MonthlySchedule.h PaymentSchedule.h
Affiliation.o: Affiliation.cpp Affiliation.h
BiweeklySchedule.o: BiweeklySchedule.cpp BiweeklySchedule.h \
 PaymentSchedule.h Date.h
ChangeAddressTransaction.o: ChangeAddressTransaction.cpp \
 ChangeAddressTransaction.h ChangeEmployeeTransaction.h Transaction.h \
 Employee.h
ChangeAffiliationTransaction.o: ChangeAffiliationTransaction.cpp \
 ChangeAffiliationTransaction.h ChangeEmployeeTransaction.h \
 Transaction.h Employee.h
ChangeClassificationTransaction.o: ChangeClassificationTransaction.cpp \
 ChangeClassificationTransaction.h ChangeEmployeeTransaction.h \
 Transaction.h Employee.h
ChangeCommissionedTransaction.o: ChangeCommissionedTransaction.cpp \
 ChangeCommissionedTransaction.h ChangeClassificationTransaction.h \
 ChangeEmployeeTransaction.h Transaction.h Employee.h \
 BiweeklySchedule.h PaymentSchedule.h CommissionedClassification.h \
 PaymentClassification.h Date.h
ChangeDirectTransaction.o: ChangeDirectTransaction.cpp \
 ChangeDirectTransaction.h ChangeMethodTransaction.h \
 ChangeEmployeeTransaction.h Transaction.h Employee.h DirectMethod.h \
 PaymentMethod.h
ChangeEmployeeTransaction.o: ChangeEmployeeTransaction.cpp \
 ChangeEmployeeTransaction.h Transaction.h Employee.h \
 PayrollDatabase.h
ChangeHoldTransaction.o: ChangeHoldTransaction.cpp \
 ChangeHoldTransaction.h ChangeMethodTransaction.h \
 ChangeEmployeeTransaction.h Transaction.h Employee.h HoldMethod.h \
 PaymentMethod.h
ChangeHourlyTransaction.o: ChangeHourlyTransaction.cpp \
 ChangeHourlyTransaction.h ChangeClassificationTransaction.h \
 ChangeEmployeeTransaction.h Transaction.h Employee.h WeeklySchedule.h \
 PaymentSchedule.h HourlyClassification.h PaymentClassification.h \
 Date.h
ChangeMailTransaction.o: ChangeMailTransaction.cpp \
 ChangeMailTransaction.h ChangeMethodTransaction.h \
 ChangeEmployeeTransaction.h Transaction.h Employee.h MailMethod.h \
 PaymentMethod.h
ChangeMemberTransaction.o: ChangeMemberTransaction.cpp \
 ChangeMemberTransaction.h ChangeAffiliationTransaction.h \
 ChangeEmployeeTransaction.h Transaction.h Employee.h \
 UnionAffiliation.h Affiliation.h PayrollDatabase.h
ChangeMethodTransaction.o: ChangeMethodTransaction.cpp \
 ChangeMethodTransaction.h ChangeEmployeeTransaction.h Transaction.h \
 Employee.h
ChangeNameTransaction.o: ChangeNameTransaction.cpp \
 ChangeNameTransaction.h ChangeEmployeeTransaction.h Transaction.h \
 Employee.h
ChangeSalariedTransaction.o: ChangeSalariedTransaction.cpp \
 ChangeSalariedTransaction.h ChangeClassificationTransaction.h \
 ChangeEmployeeTransaction.h Transaction.h Employee.h \
 MonthlySchedule.h PaymentSchedule.h SalariedClassification.h \
 PaymentClassification.h
ChangeUnaffiliatedTransaction.o: ChangeUnaffiliatedTransaction.cpp \
 ChangeUnaffiliatedTransaction.h ChangeAffiliationTransaction.h \
 ChangeEmployeeTransaction.h Transaction.h Employee.h NoAffiliation.h \
 Affiliation.h UnionAffiliation.h PayrollDatabase.h
CommissionedClassification.o: CommissionedClassification.cpp \
 CommissionedClassification.h PaymentClassification.h Date.h \
 SalesReceipt.h Paycheck.h
Date.o: Date.cpp Date.h
DeleteEmployeeTransaction.o: DeleteEmployeeTransaction.cpp \
 DeleteEmployeeTransaction.h Transaction.h PayrollDatabase.h
DirectMethod.o: DirectMethod.cpp DirectMethod.h PaymentMethod.h \
 Paycheck.h Date.h
Employee.o: Employee.cpp Employee.h NoAffiliation.h Affiliation.h \
 PaymentClassification.h PaymentSchedule.h PaymentMethod.h Paycheck.h \
 Date.h
HoldMethod.o: HoldMethod.cpp HoldMethod.h PaymentMethod.h Paycheck.h \
 Date.h
HourlyClassification.o: HourlyClassification.cpp \
 HourlyClassification.h PaymentClassification.h Date.h TimeCard.h \
 PayCheck.h
MailMethod.o: MailMethod.cpp MailMethod.h PaymentMethod.h Paycheck.h \
 Date.h
MonthlySchedule.o: MonthlySchedule.cpp MonthlySchedule.h \
 PaymentSchedule.h Date.h
NoAffiliation.o: NoAffiliation.cpp NoAffiliation.h Affiliation.h
Paycheck.o: Paycheck.cpp Paycheck.h Date.h
PaydayTransaction.o: PaydayTransaction.cpp PaydayTransaction.h \
 Transaction.h Date.h PayrollDatabase.h Paycheck.h Employee.h
PaymentClassification.o: PaymentClassification.cpp \
 PaymentClassification.h
PaymentMethod.o: PaymentMethod.cpp PaymentMethod.h
PaymentSchedule.o: PaymentSchedule.cpp PaymentSchedule.h
PayrollDatabase.o: PayrollDatabase.cpp PayrollDatabase.h Employee.h
PayrollTest.o: PayrollTest.cpp PayrollTest.h \
 c:/cppunit1.5/CppUnit/test/framework/TestCase.h \
 c:/cppunit1.5/CppUnit/test/framework/Guards.h \
 c:/cppunit1.5/CppUnit/test/framework/Test.h \
 c:/cppunit1.5/CppUnit/test/framework/CppUnitException.h \
 c:/cppunit1.5/CppUnit/test/framework/TestSuite.h \
 c:/cppunit1.5/CppUnit/test/framework/TestCaller.h PayrollDatabase.h \
 AddSalariedEmployee.h AddEmployeeTransaction.h Transaction.h \
 Employee.h SalariedClassification.h PaymentClassification.h \
 AddHourlyEmployee.h MonthlySchedule.h PaymentSchedule.h HoldMethod.h \
 PaymentMethod.h HourlyClassification.h Date.h WeeklySchedule.h \
 AddCommissionedEmployee.h CommissionedClassification.h \
 BiweeklySchedule.h DeleteEmployeeTransaction.h TimeCardTransaction.h \
 TimeCard.h SalesReceiptTransaction.h SalesReceipt.h \
 UnionAffiliation.h Affiliation.h ServiceChargeTransaction.h \
 ServiceCharge.h ChangeNameTransaction.h ChangeEmployeeTransaction.h \
 ChangeAddressTransaction.h ChangeHourlyTransaction.h \
 ChangeClassificationTransaction.h ChangeSalariedTransaction.h \
 ChangeCommissionedTransaction.h ChangeMailTransaction.h \
 ChangeMethodTransaction.h MailMethod.h ChangeDirectTransaction.h \
 DirectMethod.h ChangeHoldTransaction.h ChangeMemberTransaction.h \
 ChangeAffiliationTransaction.h ChangeUnaffiliatedTransaction.h \
 NoAffiliation.h PaydayTransaction.h Paycheck.h
SalariedClassification.o: SalariedClassification.cpp \
 SalariedClassification.h PaymentClassification.h
SalesReceipt.o: SalesReceipt.cpp SalesReceipt.h Date.h
SalesReceiptTransaction.o: SalesReceiptTransaction.cpp \
 SalesReceiptTransaction.h Transaction.h Date.h Employee.h \
 PayrollDatabase.h CommissionedClassification.h \
 PaymentClassification.h SalesReceipt.h
ServiceCharge.o: ServiceCharge.cpp ServiceCharge.h
ServiceChargeTransaction.o: ServiceChargeTransaction.cpp \
 ServiceChargeTransaction.h Transaction.h Employee.h ServiceCharge.h \
 PayrollDatabase.h UnionAffiliation.h Affiliation.h
TestRunner.o: TestRunner.cpp \
 c:/cppunit1.5/cppunit/test/textui/TextTestResult.h \
 c:/cppunit1.5/CppUnit/test/framework/TestResult.h \
 c:/cppunit1.5/CppUnit/test/framework/Guards.h \
 c:/cppunit1.5/CppUnit/test/framework/TestFailure.h \
 c:/cppunit1.5/CppUnit/test/framework/CppUnitException.h PayrollTest.h \
 c:/cppunit1.5/CppUnit/test/framework/TestCase.h \
 c:/cppunit1.5/CppUnit/test/framework/Test.h \
 c:/cppunit1.5/CppUnit/test/framework/TestSuite.h \
 c:/cppunit1.5/CppUnit/test/framework/TestCaller.h
TimeCard.o: TimeCard.cpp TimeCard.h Date.h
TimeCardTransaction.o: TimeCardTransaction.cpp TimeCardTransaction.h \
 Transaction.h Date.h Employee.h PayrollDatabase.h \
 HourlyClassification.h PaymentClassification.h TimeCard.h
Transaction.o: Transaction.cpp Transaction.h
UnionAffiliation.o: UnionAffiliation.cpp UnionAffiliation.h \
 Affiliation.h ServiceCharge.h
WeeklySchedule.o: WeeklySchedule.cpp WeeklySchedule.h \
 PaymentSchedule.h Date.h

