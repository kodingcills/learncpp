#include <iostream>
using namespace std;

/**
 * function = named, reusable chunk of code.
 * Write it once, call it forom anywhere
 * Use it whe. there's repetitive logic or for cleanliness of code
 * 
 * prototype = one-line declaration that tells the compiler the function exists
 * definition - the actual body implementation of it
 * call - where you actually use it
 * parameter - variable name used inside function deifnition
 * argument - values passed into the parameters when callinf
 * return type - what type of value the function gives back
 * void - return type meaning "gives nothing back"
 * scope - where a variable exists and can be seen
 */

 //prototype declaration before the function exists as its defined later
int square(int n);
int main() {
    int result = square(5);
    cout << result;
    return 0;
}

//definition
int square(int n){
    return n*n;
}

/**
 * SCOPE
 * decides where a cvariable can be seena dn sued
 * scope makes functions self contained what happens in a fucntion stysa in a function
 * 
 * scope - region of code where a variable exists and can be used
 * local variable - var declared inside a function, dies when function ends
 * global variable - declared outside all functions, visible everywhere
 */

