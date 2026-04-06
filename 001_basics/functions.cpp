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

int main() {
    cout << square(2) << endl;
    cout << average(3.0,1.0,4.0) << endl;
    int x = 2;
    int y = 4;
    swap(x,y);
    cout << x << " " << y;
    cout << isEven(3);
}