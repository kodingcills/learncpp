#include <iostream>
using namespace std;

int* makeArray(int size, int fillValue){
    int *arr = new int[size];
    for(int i =0; i < size; i++){
        arr[i] = fillValue;
    }
    return arr;
}

int* resizeArray(int* old, int oldSize, int newSize){
    int* arr = new int[newSize];
    for(int i = 0; i < oldSize; i++){
        arr[i] = old[i];
    }
    for(int i = oldSize; i < newSize; i++){
        arr[i] = 0;
    }
    delete[] old;
    old = nullptr;
    return arr;
}

int main(){
    int* x = new int(99);
    cout << *x << endl;
    delete x;
    x = nullptr;

    int* arr = makeArray(5,7);
    for(int i = 0; i < 5; i++){
        cout << arr[i] << endl;
    }
    delete[] arr;
    arr = nullptr;

    int * arr1 = makeArray(3,6);
    arr1 = resizeArray(arr1,3,7);
    for(int i = 0; i < 7; i++){
        cout << arr1[i] << endl;
    }
    delete[] arr1;
    arr1=nullptr;
}