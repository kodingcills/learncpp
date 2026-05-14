#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

char letterGrade(int score);
double gradePoints(char letter);
void printReport(string name, int score, double gpa);
bool isHonors(double gpa);

int main() {
    string name;
    int score;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter score: ";
    cin >> score;
    char letter = letterGrade(score);
    double gradepoint = gradePoints(letter);
    printReport(name, score, gradepoint);
    bool honors = isHonors(gradepoint);
    if (honors){
        cout << "Honors student" << endl;
    }else{
        cout << "Not honors" << endl;
    }
    return 0;
}

char letterGrade(int score){
    if (score>=90){
        return 'A';
    }else if (score>=80){
        return 'B';
    }else if(score>=70){
        return 'C';
    }else if(score>=60){
        return 'D';
    }else{
        return 'F';
    }
}

double gradePoints(char letter){
    switch(letter){
        case 'A':
            return 4.0;
        case 'B':
            return 3.0;
        case 'C':
            return 2.0;
        case 'D':
            return 1.0;
        case 'F':
            return 0.0;
        default:
            return -1.0;
    }
}

void printReport(string name, int score, double gpa){
    cout << "Report for " << name << " is " << fixed << setprecision(2) << score << " score" << endl;
    cout << "GPA for " << name << " is " << fixed << setprecision(2) << gpa << " GPA points" << endl;
}

bool isHonors(double gpa){
    return gpa >=3.5;
}