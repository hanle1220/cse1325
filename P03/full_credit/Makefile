CXXFLAGS += --std=c++17

match: main.o board.o tile.o *.h
	$(CXX) $(CXXFLAGS) -c match main.o board.o tile.o
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
board.o: board.cpp *.h
	$(CXX) $(CXXFLAGS) -c board.cpp -o board.o
tile.o: tile.cpp *.h
	$(CXX) $(CXXFLAGS) -c tile.cpp -o tile.o

tile.gch: tile.h
	$(CXX) $(CXXFLAGS) -c tile.h -o tile.gch

clean:
	rm -f *.o *.gch ~* a.out match

