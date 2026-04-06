#include <iostream> 
using namespace std;

int main(){
    int score = 87;
    double gpa = 3.6;
    if (score >=90) { 
        cout << "A";
    }else if (score >=80) { 
        cout << "B";
    }else if (score >=70){
        cout << "C";
    }else if (score  >=60){
        cout << "D";
    }else{
        cout << "F";
    }

    int year = 2;
    switch(year){
        case 2:
        cout << "Sophomore";
        case 3:
        cout << "Junior";
        case 4:
        cout << "Senior";
        default:
        cout << "Unknown";
    }

    cout << "Score: " << score << "\nGPA: " << gpa;
}