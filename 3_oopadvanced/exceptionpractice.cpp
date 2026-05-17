#include <iostream>
using namespace std;

/**
 * 1. 
 * one
 * two
 * three
 * 99
 * after three
 * after two
 * after one
 * int: 99
 */

double safeDivide(double a, double b){
    if (b==0){
        throw string("Division by 0");
    }
    return a/b;
}

int main() {
    // Your code goes here
    try{
        double result = safeDivide(4.0,0);
        cout << "result: " << result << endl;
    }catch(string s){
        cout << "Error: " << s << endl;
    }
    try{
        double result = safeDivide(2.0,4.0);
        cout << "result: " << result << endl;
    }catch(string s){
        cout << "Error: " << s << endl;
    }catch(double d){
        cout << d << endl;
    }
    return 0;
}

/**
 * 3. a) false, nothing after the throw returns because it's acting as a return almost
 * b) true because catch(...) catches any type of variable, which can be used as a defaulta s the last catch statement
 * c) true
 * d) falase
 */