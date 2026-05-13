#include <iostream>
using namespace std;
int main(){
    int score;
    double gpa;
    cout << "Enter grade:" << endl;
    char c;
    cin >> score;
    if (score >= 90){
        gpa = 4.0;
        c = 'A';
        cout << c << endl;
    } else if (score >= 80){
        gpa = 3.0;
        c = 'B';
        cout << c << endl;
    } else if (score >= 70){
        gpa = 2.0;
        c = 'C';
        cout << c << endl;
    } else{
        gpa = 1.0;
        c = 'D';
        cout << c << endl;
    }
    switch(c){
        case 'A':
            cout << "Star student! GPA is " << gpa << endl;
        case 'B':
            cout << "B! GPA is " << gpa << endl;
        case 'C':
            cout << "Meets requirements!GPA is " << gpa << endl;
        case 'D':
            cout << "Failed with a " << gpa << endl;
        default:
            cout << "Uh oh" << endl;
    }
    return 0;
}