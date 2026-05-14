/**
 * target: dependency1 dependency2...
 * [TAB] command
 * 
 * Animal.o: Animal.cpp Animal.h
 *      g++ -Wall -c Animal.cpp
 * 
 * Target = animal.o
 * dependencies = Animlal.cpp Animal.h
 * Command: g++ -Wall -c Animal.cpp
 * 
 * compie one .cpp into one .o always use -c 
 * 
 * for the executible, link all .o files into the final program do not use -c or -o
 * 
 * proj: main.o Animal.o Dog.o
 *      g++ -Wall main.o Animal.o Dog.o -o proj -o is the output name it produces the executible
 * 
 * 
 * MAXROS
 * Variables for the makefile
 * Instaed of typing g++ and _wall everywhere
 * CXX = g++
 * CXXFLAGS = -Wall
 * 
 * 
 * so youw ould use $(CXX) which expands to g++
 * ($CXXFLAGS) expands to -Wall
 * -c means compile code without linking
 * 
 */