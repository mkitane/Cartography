COMP = g++
EDL = g++
RM = rm 
EXE = analog
CLEAN = efface
CPPFLAGS = -std=c++11 -c -Wall -Wno-deprecated-writable-strings
RMFLAGS = -f

TESTSPATH = tests/

INTERFACE = B3409_class.h
REAL = B3409_class.cpp B3409_tests.cpp $(TESTSPATH)Add_tests.cpp $(TESTSPATH)FindDMP_tests.cpp $(TESTSPATH)GetData_tests.cpp $(TESTSPATH)testsFonctionels.cpp
OBJ = $(REAL:.cpp=.o)


.PHONY : $(CLEAN)

$(EXE) : $(OBJ)
	$(EDL) -std=c++11 -o $(EXE) $(OBJ)

%.o : %.cpp
	$(COMP) $(CPPFLAGS) $< -o $@

$(CLEAN) :
	$(RM) $(RMFLAGS) *.o $(TESTSPATH)*.o $(EXE) core
