#include <iostream>
using namespace std;
int main(){
    for(int i = 2; i <= 20; i+=2){
        cout << i;
    }
    cout << endl;
    int n = 1;
    while (n < 1000){
        n = n *2;
    }
    cout << n << endl;
    int c = 5;
    do{
        cout << c << endl;
        c--;
    } while(c >= 1);
    cout << "Liftoff!" << endl;
    for(int i = 1; i <= 5; i++){
        for(int j = 0; j < i; j++){
            cout << "*";
        }
        cout << endl;
    }
}