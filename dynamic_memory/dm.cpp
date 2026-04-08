#include <iostream>
using namespace std;

void init(int*&data, int& capacity, int& size, int initialCapacity){
    data = new int[initialCapacity];
    capacity = initialCapacity;
    size = 0;
}

void append(int*&data, int& capacity, int& size, int value){
    if(size == capacity){
        capacity *= 2;
        int * temp = new int[capacity];
        for(int i = 0; i < size; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }

    data[size] = value;
    size ++; 
    
}

void removeAt(int *& data, int & size, int index){
    if (index >= size || index < 0){
        cout <<"Invalid index" << endl;
    }else{
        for(int i = index; i < size -1; i ++) {
            data[i] = data[i+1];
        }
        size --;
    }
}

int search(int * data, int size, int target){
    for(int i = 0; i < size; i++){
        if(data[i] == target){
            return i;
        }
    }
    return -1;
}

void destroy(int *& data, int & capacity, int &size){
    delete[] data;
    data = nullptr;
    capacity = 0;
    size = 0;
}

void print(int* data, int size){
    for(int i = 0; i < size; i++){
        cout << "[" << i << "]" << ": " << data[i] << endl;
    }
}

int main() {
    int * data = nullptr;
    int capacity = 0;
    int size = 0;
    init(data,capacity,size,3);
    cout << capacity << endl;
    append(data, capacity, size, 1);
    append(data, capacity, size, 2);
    append(data, capacity, size, 3);
    append(data, capacity, size, 4);
    append(data, capacity, size, 5);
    print(data, size);
    cout << capacity << endl;
    cout << search(data, size, 2);
    removeAt(data, size, 1);
    print(data,size);
    removeAt(data, size, -1);
    destroy(data, capacity, size);
    if(data == nullptr){
        cout << "Data is null" << data << endl;
    }else{
        cout << "data is not null" << data << endl;
    }
}