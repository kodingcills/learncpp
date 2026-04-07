#include <iostream>
using namespace std;

//stack sies whenever the scope ends
int* danger() {
    int x =42;
    return &x; // x is destroyed when the function returns, the pointer is a nullpointer
}

int*safe() { 
    int *x = new int(42); //x is a pointer to the memory address of new int 42, new int(42) returns the memory address of 42
    return x; // heap survives and the caller is responsible for deleting it, not deleted when the function returns 
}
int main() {
    /**
     * so far memory has been automatically maanged, allocated when a variable is declared, freed when it goes out of scope
     * dyhamic memory lives on the heap - you control when it's allocated and freed
     */

    /**
     * heap = large pool of memory that awlays stays alive
     * scope = the visibility nad lifetime of a variable, like for example local variavles vs glo al variables
     * Automatic lifetime: when [you declare x=5, it is created on the stack, when the program reaches the closing bracket, the variable is automatically destroyed and the memory is reclaied instantly to the heap
     * 
     * STACK VS HEAP
     * stack is manual, int x= = 10;
     * heap is dynamic, int *p = new int(10);
     * stack ends when the program ends, heap ends when you say delete
     * heap size is bigger than stack becasue it's limited only by your RAM
     */

    int * p = new int; // allocate one int on the heap
     /**
      * 1. creates a pointer p on the stack, but then tells the OS to go to the heap, find a celan memroy spot for 1 integer, then gives it that address. Now p holds a valid, specific address on the heap
      */
     // different from *p because it's aytomatic/stack because it creates a pointer p on the stack, so it's a wild pointer containing garbage and doesn't have a valid integer ye
     *p = 42; // stores a value in that int pointer
     cout << *p; //reference and use it
     delete p; //YOU havae to delete the pointer becausec++ wont, delete frees it. Forgetting delete leads to a memory leak, too many non deleted dytnamic pointers make you run out of RAM and crash
    p = nullptr; // after deleting pointer, null it. Make it null after deleting so that the memory is not only opened for reuse, but so that hte p still holds the adress of that memory. This is a dangling pointer, it's good practice

    /**
     * HEAP ARRAYS
     */
    int* arr = new int[5]; //allocate array of 5 clean ints on the heap
    arr[0] = 10; //used exactly like a stack array
    arr[1] = 20;
    delete[] arr;
    arr = nullptr;

    /**
     * Use dynamic heap memory to address stack memory limitations
     */
    // stack size is fixed at compile time
    int size = 5;
    int arr[size]; // illegal because it has to be a compile time constant

    //heap memory can be sized at runtime with input
    int size;
    cin >> size;
    int * arr = new int[size]; // correct

    int * abc = new int(42);
    

}