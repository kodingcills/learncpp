#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int square(int n);// functio prototype - just hte signature, semicolon

int main() {
    srand(time(NULL)); // seed once at the start of main - never inside a loop;
    int r = rand() % 10 + 1; // 10 us tge end 1 is the start
    //general range: (rand() % (MAX+1-MIN)) + MIN

    ifstream inFile;
    inFile.open("data.txt"); //connect to file

    int x; 
    inFile >> x; // like cin >> x but writes to fikle

    inFile.close();
    

    // ifstream = input ofstraem - output

    /**
     * CSTRING vs string
     */

     char name[5] = "John"; // 0-4 characters + null
     char name[5] = {'j', 'o', 'h', 'n', '\0'}; // same thing

     //string class - normal
     string s = "JOHN";
     s[0]; // J
     s.at(0); // "J", sane, but with bounds checking

     //key difference: can't compare c string with euqlaity operator ==

     char a[] = "hi";
     char b[] = "hi";
     a == b; // compares the addresses, nt the actual content
     strcmp(a,b); // returns 0 if equal

     //a, b = stringa a == b worjs
}

int square(int n ){
    return n*n; // definition below main
 }