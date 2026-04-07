#include <iostream>
using namespace std;

void setup(int*& buffer, int & capacity, int & size, int initialCap){
    /**
     * what *& does is it points to the dynamic arracy buffer and changes it directly
     * * = pass by pointer, the value at the address but not hte address itself
     * int & = referecne = value of the variable directly
     * *7 = value and pointer's address for resizing/allocating memory on the heap
     * 
     * void update(int * p)
     *  p = new int(10); //p is a copy of the pointer only for hte local copy
     * *p = 10 //  modifying original value of p to 10
     * p = 10 assigns a value to an int
     * p = new int(10) assigns the address of 10 to p, a pointer
     */
    buffer = new int[initialCap];
    capacity = initialCap;
    size = 0;
}

void push(int *& buffer, int & capacity, int & size, int value){
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

void pop(int * buffer, int & size){
    if(size == 0){
        cout << "Buffer Underflow" << endl;
    } else{
        size--;
    }
}

void squeeze(int *& buffer, int & capacity, int size){ // using pass by pointer reference wiht *& because we are allocating/resizing the buffer array
    int * temp = new int[size];
    for(int i = 0; i < size; i++){
        temp[i] = buffer[i];
    }
    delete[] buffer;
    buffer = temp;
    capacity = size;
}

void reverse(int * buffer, int size){
    for(int i = 0; i < size/2; i++){
        int temp = buffer[size-1-i];
        buffer[size-1-i] = buffer[i];
        buffer[i] = temp;
    }
}

void clear(int *& buffer, int & capacity, int & size){
    delete[] buffer;
    buffer = nullptr; 
    capacity = 0;
    size = 0;
}

int main() {
    int* buffer = nullptr;
    int capacity = 0;
    int size = 0;

    setup(buffer, capacity, size, 2);
    push(buffer, capacity, size, 10);
    push(buffer, capacity, size, 20);
    push(buffer, capacity, size, 30); // Triggers triple resize
    
    // Test your new functions here!
    reverse(buffer, size);
    squeeze(buffer, capacity, size);
    clear(buffer, capacity, size);

    return 0;
}