#include <iostream>
using namespace std;

void fillArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i] = i+1;
    }
}

int sumArray(int arr[], int size){
    int sum = 0;
    for(int i = 0; i<size; i++){
        sum += arr[i];
    }
    return sum;
}

int findMax(int arr[], int size){
    int n = arr[0];
    for(int i =0; i < size; i++){
        if(arr[i] > n){
            n = arr[i];
        }
    }
    return n;
}

void reverseArray(int arr[], int size){
    int left = 0;
    int right = size - 1;
    while (left < right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left ++;
        right --;
    }
}

int main() {
    int arr[5] = {};
    fillArray(arr, sizeof(arr)/sizeof(arr[0]));
    cout << "Sum: " << sumArray(arr, sizeof(arr)/sizeof(arr[0])) << endl;
    cout << "Max: " << findMax(arr, sizeof(arr)/ sizeof(arr[0])) << endl;
    reverseArray(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        cout << arr[i] << endl;
    }
}