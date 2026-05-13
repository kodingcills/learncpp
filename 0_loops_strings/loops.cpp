#include <iostream>
#include <string>
using namespace std;

// switch statement gives point of entry not point of exit, keeps falling through every case iwtohut a brreak
/***
 * 
 * switch(statement):
 *      case 1:
 *          ahdwhdaw;
 *          break;
 *      case 2:
 *          ahdwhdaw;
 *          break;
 */
// do while loop
//un tge byd first, then check condition, guaranteed at least one execution where the regular while loop doesn't have that
main(){
    int count = 0;
    do {
        cout << "hi "; // body runs first
        count ++;
    }while(count < 3);

    // regular while loop just checks condition first
    while (count < 3){
        cout << "while"; // checks firs,t so if the condition is false it never urns
    }

    //when to use do while - input validation
    int choice;
    do{
        cout << "Enter 1-5";
        cin >> choice;
    }while(choice < 1 || choice > 5);

    /**
     * 
     * TERNARY OPERATOR
     * shorthand if/else for a single value
     * 
     */

     // this:
     int n1,n2,max;
     if (n1 > n2){
        max = n1;
     }else{
        max = n2;
     }

    int max = (n1 > n2) ? n1 : n2;
    //         condition  ^ if true  ^ if false
}