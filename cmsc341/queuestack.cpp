#include <iostream>
using namespace std;

/**
ADT vs implementation
ADT is abstract data type, specifies:
    - what data is stored
    - what operations are supported
    - what errors can occur

does NOT say how its built internallt

*/

/**
sTACK ADT

Stack = LIFO Last in, first out

The last thing you pushed is the first thing that comes out, see it as a stack of plates its litralyl a stack of plates

push(10) → [10]
push(20) → [10, 20]
push(30) → [10, 20, 30]
pop()    → returns 30, stack is [10, 20]
top()    → returns 20, stack is still [10, 20]

Stack
push(e) - insert e at top, error case = overflow
pop - remove and return top
top - return top without removing
size - return count of elements
empty - return true if no elements
*/

/**
Array implementation of stack
t is the top index, starts at -1 because when the stack is empty there IS no top element, index -1 signals nothing here yet
*/

template<typename T>
class Stack{
    private:
        T* S;
        int t;
        int capaciy;
    public:
        Stack(int cap) : capacity(cap), t(-1){
            S = new T[capacity];
        }
};

