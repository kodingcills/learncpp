#include <iostream>
using namespace std;
//write
enum seasons { WINTER, SPRING, SUMMER, FALL };
//             0       1       2       3      ← values assigned automatically
// default values start at 0 and increment, you can overridde
enum foo { A=2, B=5, C=6, D, E=10 };
// D=7 because its the next sequential number after C, D gets C+1 automatically

/**
 * NAMED VS UNNAMED
 */
//named = creates a TYPE you can use for variables
enum seasons { WINTER, SPRINg, SUMMER, fall};
/**
 * seasons current; // variable of type seasons
 * current = FALL; // set to 3, enum is 3 because that's the indez of FALL
 * current = 7 // comile error, only valid VALUES can be set to the variable
 */

//unnamed = constants only, no ttype
enum {WINTER, SPRING, SUMMER, FALL};
/**
 * int choice;
 * cin >> Choice;
 * switch choice(){
 *  case WINTER: cout << "brr!; break;
 *  case SPARING: <<cout << "nice!"; break;
 * }
 * 
 * named gives you type safety, can only assign valid values.
 * Unnamed is a cleaner way to just write a bunch of constants
 */

 /**
  * ENUM IN A SWITCH
  */
 enum direction {NORTH, SOUTH, EAST, WEST};
 /**
  * direction d = NORTH
  * switch(d){
  *     case NORTH: cout << "Going north"; break;
  *     case SOUTH: cout << "Going south"; break;
  *     case EAST: cout <<"East"; break;
  *     case WEST: cout << "wesst"; break
  * }
  * if named enum set to a value that isnt incliuded, like SOAUTHWEST, compile error
  */
int main() {
    //Enum is a named list of integer constants, Instead of:
    const int WINTER = 0;
    const int SPRING = 1;
    const int SUMMER= 2;
    const int FALL = 3;


}