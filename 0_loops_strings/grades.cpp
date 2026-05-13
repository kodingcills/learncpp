#include <iostream>
#include <string>
using namespace std;

int main(){
    int score;
    do{
        cout << "Enter a score from 0-100: ";
        cin >> score;
        char letter;
        int gpa;
        if(score>=90){
            letter = 'A';
            gpa =4;
        }else if (score>=80){
            letter = 'B';
            gpa = 3;
        }else if (score >=70){
            letter = 'C';
            gpa = 2;
        }else if(score >=60){
            letter = 'D';
            gpa = 1;
        }else{
            letter = 'F';
            gpa = 0;
        }
        for(int i = 0; i < gpa; i++){
            cout << "*";
        }
        cout << endl;
        switch(letter){
            case 'A':
                cout << "A" << endl;
                break;
            case 'B':
                cout << "B" << endl;
                break;
            case 'C':
                cout << "C" << endl;
                break;
            case 'D':
                cout << "D" << endl;
                break;
            default:
                break;
        }
        //compare to requirement for honors
        int required = 3;
        int max = (gpa>required) ? gpa : required;
    }while(score != -1);
}