#include <iostream>
#include <string>
using namespace std;

int main(){
    // string word = "hello";
    // cout << word[0]; // no bounds checking accessing individual characters
    // cout << word.at(0); // catches bugs with bounds checking and accesses individual characters


    // /**
    //  * cin stops at whitespace
    //  * input "Jean Claude" only gets "Jean"
    //  * 
    //  * to counteract this, use getline()
    //  */
    // string fullName;
    // cout << "Enter name";
    // getline(cin, fullName);
    // cout << "Hello, " << fullName;

    int age;
    string name;

    cin >> age;           // reads "25", leaves '\n' in buffer
    getline(cin, name);  // reads that \n means name is empty

    cin >> age;
    cin.ignore(); // throws away the \n stuck in the buffer
    getline(cin,name);  //now works correctly
}