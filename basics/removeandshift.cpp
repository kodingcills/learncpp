#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <cmath>
using namespace std;

int removeAll(int arr[], int size, int target){
    //2 pointer method
    int writeIndex = 0;
    // writeIndex only moves forward when we find an element that is not hte target;
    //readIndex iterates through every element of the array no matter what
    for (int readIndex = 0; readIndex < size; readIndex++){
        if(arr[readIndex] != target){
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
    }

    return writeIndex;
}

int removeAll(char arr[], int size, char target){
    int left = 0;
    for(int right = 0; right < size; right++){
        if(arr[right] != target){
            arr[left] = arr[right];
            left++;
        }
    }
    return left;
}

bool isPalindrome(string s){
    int left = 0;
    for(int right = s.length()-1; right >0; right--){
        if(s[left] != s[right]){
            return false;
        }
        left ++;
    }
    return true;
}

void squareArray(int arr[], int size){
    int temp[size];
    for(int i = 0; i < size; i++){
        temp[i] = arr[i]*arr[i];
    }
    int left = 0;
    for(int right = size - 1; right > 0; right--){
        if(temp[left] > temp[right]){
            int t = temp[right];
            temp[right] = temp[left];
            temp[left] = t;
        }
        left ++ ;
    }
}

int container(int height[], int size){
    int left = 0;
    int right = size-1;
    int temp;
    if(height[left] > height[right]){
        temp = height[right];
    }else{
        temp = height[left];
    }
    int volume = temp * (right-left);
    while(left<right){
        if(height[left] > height[right]){
            temp = height[right];
        }else{
            temp = height[left];
        }
        int tempv = temp * (right-left);
        if(tempv>volume){
            volume = tempv;
        }
        left++;
    }
    return volume;
}

int main(){
    int arr1[8] = {3,1,3,2,3,4,3,5};
    int sizeArr1 = sizeof(arr1)/sizeof(arr1[0]);
    int n = removeAll(arr1, sizeArr1, 3);
    cout << "New size " << n << endl;
    for( int i = 0; i < n; i ++){
        cout << arr1[i] << endl;
    }

    char arr2[6] = {'a','b','a','c','a','b'};
    int sizeArr2 = sizeof(arr2)/sizeof(arr2[0]);
    int n1 = removeAll(arr2, sizeArr2, 'a');
    cout << "New size " << n1 << endl;
    for(int i  =0 ; i < n1; i++){
        cout << arr2[i] << endl;
    }

    int test1[] = {1,1,1,1,1};
    int test1Size = removeAll(test1, 5, 1);
    cout << "New size " << test1Size << endl;
    for(int i  =0 ; i < test1Size; i++){
        cout << test1[i] << endl;
    }

    int test2[] = {0,0,0,0,0};
    int test2Size = removeAll(test2, 5, 1);
    cout << "New size " << test2Size << endl;
    for(int i  =0 ; i < test2Size; i++){
        cout << test2[i] << endl;
    }
}