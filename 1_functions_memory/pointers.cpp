/**
 * address - unique nunmber identifying where it lives in memory
 * pointer - variable whose cvalue is a memorua ddress
 * & address of gives memorya ddress
 * & is address of aoerator
 * * is derference operator it follows a pointer to the value it points at
 * * declaration makes the variable a pointer type to point to where it is in the fucking memory address
 * nullptr - pointer pointing nowhere in memory
 */
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 20;
    int *ptr = &x;
    *ptr = 50;
    ptr = &y;
    *ptr = *ptr + 5;

    cout << x << " " << y << endl;
    return 0;
}

/**
 * 
 * passing ptrs into functions
 * 
 * pass by ptr - passing the memory address as an argument to modify the original pass by reference
 * formal parameter - pointer variable in the function decalration
 * ctual argument - the address you pass in at the clall site 
 * this is a way to change by reference
 */

//ads 2 to both values and modify originals
void addTwo(int *ptr1, int *ptr2){
    *ptr1 = *ptr1 + 2; // follow ptr2, change what's There
    *ptr2 = *ptr2 + 2;
}

/**
 * 
int main() {
    int a = 10, b = 20;
    addTwo(&a, &b);     // pass addresses, not values
    cout << a << " " << b; // 12 22
    return 0;
}
 */