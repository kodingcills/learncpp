#include <iostream>
using namespace std;

int square(int n){
    return n*n;
}

double average(double a, double b, double c){ //example of pass hby value, gets a copy
    return (a+b+c)/3;
}

void swap(int &x, int &y){ // pass my reference, as in the fucntion changes the actual variable, it is in "reference to" the varialbe, changes the real variable
    int tempx = x;
    int tempy = y;
    x=tempy;
    y=tempx;
}

bool isEven(int n){
    return n%2==0;
}

/**
 * FUNCTIONS OVERLOADING
 * same function name, different parameter signature
 */

 double product(double a, double b){
    return a*b;
 }

 double product(double a, double b, double c){
    return a*b*c;
 }
 
 // must differ in number or type of parameters, return type alone doesn't count, int f() and double f() are illegal
/**
 * VALID OVERLOADS
 * double area(double r);            // circle
double area(double l, double w);  // rectangle
int    area(int l, int w);        // rectangle with ints

double area(double x, double y) {
    return x * y;
}

int area(int x, int y) {
    return x * y;
}
IS NORMAL OVERLOADING

int area(double x, double y);
double area(double x, double y); // ❌ not allowed becaus eparameter list is identical. PARAMETER LIST HAS TO DIFFER
 */

/**
 * DEFAULT ARGUEMNTS
 */

 void printBox(int width, int ehight, char fill = '*'){
    //if fill not provided, it uses '*";"
 }

void print(const string & s){ // faster, no copy, safe as in you can't modify it because it's a constant but you're still addressingthe actual variable value in the memroy
    cout << s;
    // s = "hi" ; // compiler error
    //cout prevents accidental modificatio 

}
int main() {
    cout << square(2) << endl;
    cout << average(3.0,1.0,4.0) << endl;
    int x = 2;
    int y = 4;
    swap(x,y);
    cout << x << " " << y;
    cout << isEven(3);
}