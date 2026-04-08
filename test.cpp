#include <iostream>
#include <string>
using namespace std;

void displayAgeStats(int ages[], int size);

int main(){
    const int SIZE = 6;
    int a[SIZE] = {15,22,17,24,18,12};
    displayAgeStats(a,SIZE);
    return 0;
}

void displayAgeStats(int ages[], int size){
    int youngest = ages[0];
    int oldest = ages[0];
    int a = 0;
    int m = 0;
    for(int i = 0; i < size; i ++){
        if(ages[i] > oldest){
            oldest = ages[i];
        }else if (ages[i] < youngest){
            youngest = ages[i];
        }

        if(ages[i] >=18){
            a++;
        }else{
            m++;
        }
    }
    cout << "Youngest age: " << youngest << endl;
    cout << "Oldest age: " << oldest << endl;
    cout << "Adults: " << a << endl;
    cout << "Minors: " << m << endl;
}