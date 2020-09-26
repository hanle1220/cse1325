CXXFLAGS = --std=c++17

all: gate

gate: gate.o 
	$(CXX) $(CXXFLAGS) gate.o -o gate

gate.o: gate.cpp 
	$(CXX) $(CXXFLAGS) -c gate.cpp -o gate.o

clean: 
	rm -f *.o *.gch -* a.out gate
