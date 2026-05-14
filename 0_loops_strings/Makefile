CXX = g++
CXXFLAGS = -Wall

proj: main.o Animal.o Dog.o
	$(CXX) $(CXXFLAGS) main.o Animal.o Dog.o -o proj
main.o: main.cpp Animal.h Dog.h
	$(CXX) $(CXXFLAGS) -c main.cpp
Animal.o: Animal.cpp Animal.h
	$(CXX) $(CXXFLAGS) -c Animal.cpp
# each .o's dependency list is whatever it includes, so because dog inherits form animal it includes the animal header but not the cpp implementation of it, but every .o needs the cpp and the .h
Dog.o: Dog.cpp Dog.h Animal.h
	$(CXX) ($CXXFLAGS) -c Dog.cpp