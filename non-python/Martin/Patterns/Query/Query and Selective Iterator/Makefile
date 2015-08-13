LDLIBS = -lstdc++ -lframework -ltextui
CPPFLAGS = -I "c:\cppunit1.5\CppUnit\test\framework" -I "c:\cppunit1.5\cppunit\test\textui"
LDFLAGS = -L "c:\cppunit1.5\CppUnit\test\framework" -L "c:\cppunit1.5\CppUnit\test\textui"

TestRunner : TestRunner.o QueryTestCase.o
	$(CC) -o TestRunner $(LDFLAGS) $? $(LOADLIBES) $(LDLIBS)

depend : 
	gcc -MM ${CPPFLAGS} *.cpp

