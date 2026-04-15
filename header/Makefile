CXX = g++
CXXFLAGS = -Wall
music: Guitar.o main.o
	$(CXX) $(CXXFLAGS) main.o Guitar.o -o music
Guitar.o: Guitar.cpp Guitar.h Instrument.h
	$(CXX) -c Guitar.cpp
main.o: main.cpp Guitar.h Instrument.h 
	$(CXX) -c main.cpp
Instrument.o: Instrument.cpp Instrument.h
	$(CXX) -c Instrument.cpp