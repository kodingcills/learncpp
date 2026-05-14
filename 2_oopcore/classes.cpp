#include <iostream>
using namespace std;

/**
 * abstraction - hiding how something works using cout without knowign internals
 * encapsulation - data and the functions that operate on the data together in the same calss
 * access specifiers - pbulic is accessible anywhere
 * private - accessible only ithin the scope of that class, insside member functions of that calss
 * protected - derived classes (inheritnnce)
 * 
 * :: used to tell the compiler which classs the function belongs to  wen defining from the header
 * 
 * Initialization lists 
 * ClassName(int i) : m_x(i) {}
 * Point(int i = 0) : m_x(i) {}
 * consturctors have o return type and it helps initialize an object
 * destructor - called automatically when an object is destroyed to clean up the memory
 */

/**
 * 
 * VECTORS - resizable array #include <vector>
 * .at() to access, not []
 * 
 * pass by reference to avoid copies
 * vector<int>& x;
 * (int)v.size() to access
 * push_back(val) adds to end, resize(n) sets teh size directly
 * 2d vector
 * vector<vector<int>> to access at .at(i).at(j)
 */

int main() {
    // Your code goes here
    
    return 0;
}