LDLIBS = -lstdc++ -lframework -ltextui
CPPFLAGS = -I "c:\cppunit1.5\CppUnit\test\framework" -I "c:\cppunit1.5\cppunit\test\textui"
LDFLAGS = -L "c:\cppunit1.5\CppUnit\test\framework" -L "c:\cppunit1.5\CppUnit\test\textui"

TestRunner : TestRunner.o ProductPersistenceTestCase.o product.o persistentProduct.o persistentObject.o assembly.o persistentAssembly.o
	$(CC) -o TestRunner $(LDFLAGS) $? $(LOADLIBES) $(LDLIBS)

depend : 
	gcc -MM ${CPPFLAGS} *.cpp

ProductPersistenceTestCase.o: ProductPersistenceTestCase.cpp \
 ProductPersistenceTestCase.h \
 persistentProduct.h persistentObject.h assembly.h \
 persistentAssembly.h

TestRunner.o: TestRunner.cpp \
 ProductPersistenceTestCase.h \

assembly.o: assembly.cpp assembly.h

persistentAssembly.o: persistentAssembly.cpp persistentAssembly.h \
 assembly.h persistentProduct.h product.h persistentObject.h

persistentObject.o: persistentObject.cpp persistentObject.h

persistentProduct.o: persistentProduct.cpp persistentProduct.h \
 product.h persistentObject.h

product.o: product.cpp product.h