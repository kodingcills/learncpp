# Tiffany McCormick
#CMSDC 341 SU 26
# WC51050
# Makefile for BST implementation
CXX = g++
CXXFLAGS = -Wall -g

proj1: BST.o Node.o
	$(CXX) $(CXXFLAGS) -o proj1 driver.cpp BST.o Node.o

test: mytest.cpp BST.o Node.o
	$(CXX) $(CXXFLAGS) -o test mytest.cpp BST.o Node.o

BST.o: BST.cpp BST.h Node.h
	$(CXX) $(CXXFLAGS) -c BST.cpp

Node.o: Node.cpp Node.h
	$(CXX) $(CXXFLAGS) -c Node.cpp

clean:
	rm -f *.o test proj1