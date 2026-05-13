#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string studentName;
    cout << "Name: ";
    getline(cin, studentName);
    int score;
    cout << "Score: ";
    cin >> score;
    cin.ignore();
    string subject;
    cout << "Subject: ";
    getline(cin, subject);

    ofstream output;
    output.open("grades.txt");
    output << "Name: "  << studentName << 
                "\nSubject: " << subject <<
                "\nScore: " << score;
    output.close();
}