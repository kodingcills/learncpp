#include <iostream>
using namespace std;

struct DynArray{
    int* data;
    int capacity;
    int size;
};

DynArray create(int initialCapacity){
    DynArray d;
    d.data = new int[initialCapacity];
    d.capacity = initialCapacity;
    d.size = 0;
    return d;
}

void append(DynArray& arr, int value){
    if(arr.capacity == arr.size){
        arr.capacity *= 2;
        int * temp = new int[arr.capacity];
        for(int i = 0; i < arr.size; i++){
            temp[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = temp;
    }
    arr.data[arr.size] = value;
    arr.size ++;
}

void removeAt(DynArray& arr, int index){
    if(index >= arr.size || index < 0){
        cout << "invalid index";
    }else{
        for(int i = index; i < arr.size; i++){
            arr.data[i] = arr.data[i+1];
        }
        arr.size--;
    }
}

void printArr(DynArray arr){
    for(int i = 0; i < arr.size; i++){
        cout << "[" << i << "]" << ": " << arr.data[i];
    }
}

DynArray merge(DynArray a, DynArray b){
    DynArray temp;
    temp.data = new int[a.capacity+b.capacity];
    temp.capacity = a.capacity+b.capacity;
    temp.size = a.size+b.size;
    for(int i = 0; i < a.size; i ++) {
        temp.data[i] = a.data[i];
    }
    for(int i = a.size; i < b.size+a.size; i++){
        temp.data[i] = b.data[i-a.size];
    }
    return temp;

}

void destroy(DynArray & arr){
    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
    arr.capacity = 0;
}

int main(){
    DynArray a = create(2);
    DynArray b = create(2);

    append(a, 1);
    append(a, 2);
    append(a, 3);
    printArr(a);

    append(b,1);
    append(b,2);
    append(b,3);
    printArr(b);

    DynArray c = merge(a, b);
    printArr(c);

    destroy(a);
    destroy(b);
    destroy(c);
}