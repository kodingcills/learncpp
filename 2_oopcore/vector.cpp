#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Your code goes here
    /**
     * vectors are just dynamically sized arrays that automatically resize themselves
     * 
     * 
     */

    vector<int> v; // empty vector of itns
    vector<string> names; // empty vector of strings
    vector<double> grades; // empty vector of doubles
    vector<int> v(5); // 5 elements, all 0
    vector<int> v(5,-1); // 5 elements, all -1
    vector<int> v2(v); // copy of v

    vector<int> a;
    a.push_back(10); //append to end
    a.push_back(20);
    a.push_back(30); //v=[10,20,30]

    a[0]; // accessing at 10 no bounds
    v.at(0); // bounds check
    v.front(); // first element
    v.back(); // last element

    v.size(); // returns 3 size_t nOT int
    int s = (int)v.size(); // needs to cas tto int always when using v.size();

    v.pop_back(); //removes last integer
    v.empty(); // checking if empty
    vector<int> v(3,0); // makes integer vector size 3 of all 0s
    v.resize(6); //new slots default to 0
    v.resize(8, 99); // new slots are 99
    v.resize(2); // shrinks and discards
    vector<int> v = {10, 20, 30, 40, 50};

    v.erase(v.begin() + 2);   // removes element at index 2
                            // v = [10, 20, 40, 50]
    return 0;
}