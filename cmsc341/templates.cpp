using namespace std;
#include <iostream>
template <typename T>
class Satck{
private:
    T data[100];
public:
    void push(T item);
    T pop();
};

// template definitions stay in the .h file, not split into .h and .cpp

//typedef
/**
typedef creates an alias, a new name for an existing type
*/
int main(){
    typedef int Elem; // Elem means int now
    Elem x = 5; // same as int x = 5;
}
/**
in dsa, this lets you chafne hte stored type in one place
so typedef string Elem would make it so the whole class uses string instead of int

Exam purpose typedef = type alias
*/

/**
friend

friend classes/functions hasve access to a class' private members
*/

class Node{
    private:
    int data;
    friend class Queue; // queue can see Node's private stuff as i data
};

class Vector{
    friend ostream& operator<<(ostream& out, const Vector& v);
};

//friendship is 1 imensional, Queue can see Node's privatae stuff but Node cannot see Queue's private stuff unless queue also declares node as a friend

//const means it doesnt change
//const parameter - pass by reference for speed purposes, cannot modify s
void print(const string& s){}

//const return type returns a reference, no copy and fast but the caller can't modify what's returned
//const string& getName() {return m_name;}

//const member function means the function will not modufy the object
//int size() const{return m_size;}

/**
Exceptions
deetecting and handling errors

Error Detecting - class implementor that knows when the error occurs
Errr handling - used when the class is called decides what to do about it
*/
/*
class QueueEmpty{
public:
string getMessage(){return "queue empty";}
};

Elem dequeue(){
    if(empty()) throw QueueEmpty(); // THROW
}

try{
    q.dequeue();
}catch(QueueEmpty &e){
cout << e/getMessage(); // CATCH
}

*/

/**DYnamic memory */

int* p = new int; // allocate 1 int
int* arr = new int[10]; // allocate array of 10 ints
Node* n = new Node(); // allocate one Node object

//new returns the address fo the allocate dmmeory, its stored in a pointer

//delete frees that memory
delete p; // free one object
delete[] arr; // free an array - NOTE the []

//nullptr, poineter that points to nothing as in a no vcalyue state, alwasys et to nbullptr adter deleting
int * p = new int;
p = nullptr; // memory leak, you lost the address before deleting, memoryu is still allocated but unreachable

//anytime it's dynamically allocated witha. new you need a destructor in the class

/**
GDB and valgrind */

/**
gdb file - start debugger
run - run the program
b = breakdpoint
n = next line
s = step into function
p = print value of the variable
*/

