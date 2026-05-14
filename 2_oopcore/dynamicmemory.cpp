/**
 * stack memory - local variables and aprameters, compiler time
 * heap memory - allocate on the fly while its running, exists after the thing stops running
 */

 /**
  * new allocates on heap Shoe * myShoe = new Shoe;
  * 
  * delete deletes the ptr
  * Golden rule: for every new, delete it
  * 
  * immediately after using delete, set nullptr to prevent accessing deleted memory
  * 
  * 
  */
#include <iostream>
using namespace std;

int main() {
    // Your code goes here
    
    int * p = new int; // allocates;
    delete p; // free
    p  =nullptr;

    return 0;
}