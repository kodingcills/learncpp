#include <iostream>
using namespace std;

int main() {
    // enim - list of integer constants
    enum Day { SUN, MON, TUE, WED, THU, FRI, SAT};
    Day today= TUE;
    if(today == TUE){
        cout << "Teusday";
    }

    //defualt values of it treat kt as indices
    //          0.   1.   2.   3.   4.   5.   6
    enum Day { SUN, MON, TUE, WED, THU, FRI, SAT};
    //but can override

    enum foo { A=2, B=5, C=6, D, E=10};
    //          2    5    6    7   10
    //                        ^D gets C+1 automatically

    enum Season { WINTER, SPRING, SUMMER, FALL };

    Season current = SUMMER;   // variable of type Season
    // current = 7;               // ❌ compile error — only Season values allowed

    // enum Grade { F=0, D=1, C=2, B=3, A=4 };
    // Grade g = A;
    // cout << g;   
}