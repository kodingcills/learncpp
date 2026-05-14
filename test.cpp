#include <iostream>
using namespace std;

int main() {
    // Your code goes here
    vector<int> v = {10, 20, 30, 40, 50};
                            // v = [10, 20, 40, 50]
    for(int i : v){
        cout << i << endl;
    }
}