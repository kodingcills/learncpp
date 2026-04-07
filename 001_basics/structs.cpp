#include <iostream>
using namespace std;

struct Rectangle{
    double width;
    double height;
}; // bundles related data into one named type

double area(Rectangle r){ // passed by value, function gets copy, original unchanged
    return r.width * r.height;
}

void scale(Rectangle &r, double factor) { 
    r.width *= factor;
    r.height *= factor; // function modifies original members of the instance of the object
}

void scale(Rectangle *r, double factor){ // pass by pointer. - same effect but different syntax, still mofiying origi al member sof the instance of teh bject
    r-> width *= factor; 
    r-> height *= factor;
}


/**
 * void push(int *& buffer, int & capacity, int & size, int value){
    if(size == capacity){
        capacity*=3;
        int * temp = new int[capacity];
        for(int i = 0; i < size; i ++ ){
            temp[i] = buffer[i];
        }
        delete[] buffer;
        buffer = temp;
    }

    buffer[size] = value;
    size ++;
}
 * This but in struct 
 */

struct Buffer{
    int * data;
    int capacity;
    int size;
};

void push(Buffer & b, int value){
    if(b.size == b.capacity){
        b.capacity *=3;
        int * temp = new int[b.capacity];
        for(int i = 0; i < b.size; i++){
            temp[i] = b.data[i];
        }
        delete[] b.data;
        b.data = temp;
    }
    b.data[b.size] = value;
    b.size++;
}

int main() {
    Rectangle r; //dclares an instance of Struct R
    r.width = 5.0; // dot operator to access members
    r.height = 3.0;
    cout << r.width; // 5
}