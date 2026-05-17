#include <iostream>
using namespace std;

/**
 * exceptions let you separate detection form handling
 */
//without exceptions error is handled at detection site which is whenver it sequentially come sup

bool WithDraw(double amount){
    if(amount>0){
        cout << "Insufficient"; // handler stuck
        return false;
    }
}

//with eceptions - detection here, handling whereve rthe caller wants
void withdraw(double amount){
    if(amount > 0)
        throw string("insufficent"); // throws up call stack
}


void functionerror(){
    cout << "functionerror" << endl;
    throw double(42); // theows a double
}

void function1(){
    cout << "aaa " << endl;
    functionerror(); // exception propagates up from here
}

int main() {
    // Your code goes here
    /**
     * keywords
     */
    try {
        //code that might throw
    }catch (int variable){
        //handle exception if it fails
    }

    try{
        function1();
    }catch(int i){
        cout << "int exception:" << i << endl;
    }catch(double j){
        cout << "dobule exception: " << j << endl;
    }
    /**
     * aaa
     * functionerror
     * double exception: 42
     * function1 pritns, then it calls function2 which prints, then it rhrows the double excpetion, the throw eskips everytihng and jumps tot eh matching catch block
     */

    /**
     * how propagation works
     * when throw fires, C++ unwinds the call stack to look for the matching catch statement
     * main() calls function 1
     * function1 calls function2
     * function2 throwsdouble(42)
     * unwinds function2
     * unwinds functin1
     * matches the catch(dobuel j) in the main
     * executes that cathc double blockl
     * 
     * code after throw never runs
     * code after throw and fucntion1() in the try block never runs beause the execution jumps directly tot eh matching catch block
     */

     try{
        throw 42; // throws an int
     }
     catch(double d){ // checked first, doesnt match the throw type
        cout << "double" << endl;
     }catch(int i){ // schecked second, matches the throw type
        cout << "int " << endl;
     }

     catch(...){ // catch ... catches every type and used as a safety net lsat catch block
        cout << "some exception occured" << endl;;
     }

     //if there is no matching catch, the program aborts and terminates

     //throw in a function - exception specification
    //prototype tells caller this function might throw
   // void riskyFunction() throw(string); // old style
    void riskyFunction(); // modern style - just document it doesnt need to have the throw in the prototype

    //what cna be thrown
    throw 42; // int
    throw 3.14; // double
    throw string("error"); //stirng
    throw "error"; // c string(char*)
    //throw MyException("oops") //this is a custom class obkect

    /**
     * if no exception thrown - the catch block is ignored
     * cathch(...) catches any type
     * unmatched exception - terminates
     * throw keyword signals failure and unwinds the stack it signals failure
     */
    //throw value; // signal that somthing went wrong // try catch is used in main, throw is used in fumctions for hte most part
    //value can be any type: int, string, double, object
    return 0;
}