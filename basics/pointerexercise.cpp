#include <iostream>
using namespace std;

void addOne(int* p){
    (*p)++;
}

int* findFirst(int arr[], int size, int target){
    for(int i =0; i < size; i++){
        if(*(arr+i) == target){
            return &arr[i]; // returning hte speciifc memory addreds for the pointer to pointt to
        }
    }
    return nullptr;
}


int main(){
    int x =100;
    int *ptr = &x;
    cout << x <<endl;
    cout << *(&x) << endl;
    cout << *ptr << endl;

    int y = 1;
    cout << y;
    addOne(&y);
    cout << y << endl;

    int arr[5] = {10,20,30,40,50};
    for(int i = 0; i < 5; i++){
        cout << *(arr+i) << endl;
    }

    int* find = findFirst(arr, 5, 10);
    cout << *find;
}