#include <iostream>
using namespace std;

void fillArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        arr[i] = i+1;
    }
}

int getSum(int arr[], int size){
    int total = 0;
    for (int i = 0; i < size; i++){
        total += arr[i];
    }
    return total;
}

void swap(int *a ,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void reverseArray(int arr[], int size){
    for(int i = 0; i < size/2; i++){
        swap(&arr[i], &arr[size-1-i]);
    }
}

int main() {
    const int SIZE = 5;
    int arr[SIZE];
    fillArray(arr, SIZE);
    for(int i = 0; i < SIZE; i++){
        cout << arr[i] << endl;
    }
    reverseArray(arr, SIZE);
    for(int i = 0; i < SIZE; i++){
        cout << arr[i] << endl;
    }
    cout << getSum(arr, SIZE);
    return 0;
}