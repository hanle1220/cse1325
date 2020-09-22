CXXFLAGS = --std=c++17 

all: modulo modulo2

modulo2: main2.o modulo2.o *.h
	$(CXX) $(CXXFLAGS) main2.o modulo2.o -o modulo2
modulo: main.o modulo.o *.h
	$(CXX) $(CXXFLAGS) main.o modulo.o -o modulo

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
main2.o: main2.cpp *.h
	$(CXX) $(CXXFLAGS) -c main2.cpp -o main2.o
modulo.o: modulo.cpp *.h
	$(CXX) $(CXXFLAGS) -c modulo.cpp -o modulo.o

modulo.gch: modulo.h
	$(CXX) $(CXXFLAGS) -o modulo.h -o modulo.gch
modulo2.gch: modulo2.h
	$(CXX) $(CXXFLAGS) -o modulo2.h -o modulo2.gch

clean: 
	rm -f *.o *.gch -* a.out modulo modulo2

