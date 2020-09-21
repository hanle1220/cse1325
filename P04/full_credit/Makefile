CXXFLAGS = --std=c++17 

all: modulo

modulo: main.o modulo.o *.h
	$(CXX) $(CXXFLAGS) main.o modulo.o -o modulo

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
modulo.o: modulo.cpp *.h
	$(CXX) $(CXXFLAGS) -c modulo.cpp -o modulo.o

modulo.gch: modulo.h
	$(CXX) $(CXXFLAGS) -o modulo.h -o modulo.gch

clean: 
	rm -f *.o *.gch -* a.out modulo 

