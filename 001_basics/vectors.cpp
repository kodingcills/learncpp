#include <vector>
#include <iostream>
using namespace std;
int main(){
    // a vector is dynamic, not fixed at compile time like nan array, cna grow or shrink
    //array stored on STACK vector data stored on HEAP
    vector<int> v; // empty
    vector<int> v1(10); // 10 elements of 0
    vector<int> v2(10,-1); // 10 elements of -1 so its v(amount ofelements, fillValue)
    vector<int> v3(v); //pass by value, copy of v
    v.push_back(5); //append
    v.size(); // returns size_t NOT int - must cast it
    int s =(int)v.size(); //correct castng ot it
    v[2]=7; // no bounds check, saying at index 2 set it to 7
    v.at(2) = 7; //bounds check, safer, saying at index 2 set it to 7
    v.resize(20); // grows it or shrinks it depending on the value compared to original size
    v.resize(20, 99); //grows, fill in new slot with 99, so its .resize(newSize, fillValue)
    v.erase(v.begin() +1); // requires an iterator, can't just use v.erase(1). Erases the element and every element to the right of it shifts left to fill the gap, no hole left behind the size property is properly decremented by 1
    v.begin(); /// gives you an iterator pointer that points towards tef irst element, used for loops, sorting, etc
    v.front(); // gives you the actual value of the first element
    v.back(); // gives you actual value of last eleemtn
}

//arrays default to pass by reference, vectors default ot pass by value, so you must use & for reference
void modify(vector<int>& v); //pass by reference - changes the stick
void print(const vector<int>& v); // constnat reference, so it's looking at the exacty memory address but it's read only so you can't change it