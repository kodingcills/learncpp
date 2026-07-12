# Tiffany McCormick
# CMSC341 SU 26
# WC51050
# Makefile compiles AVL tree implementation and test driver into the executable

CXX = g++
CXXFLAGS = -Wall -g

proj: AVL.o mytest.o
	$(CXX) $(CXXFLAGS) AVL.o mytest.o -o proj

AVL.o: AVL.cpp AVL.h
	$(CXX) $(CXXFLAGS) -c AVL.cpp

mytest.o: mytest.cpp AVL.h
	$(CXX) $(CXXFLAGS) -c mytest.cpp

clean:
	rm -f AVL.o mytest.o proj