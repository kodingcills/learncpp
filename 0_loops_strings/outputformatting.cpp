#include <iostream> // cout
#include <iomanip> // setw, setprecision
using namespace std;

int main(){
    //decimal precision
    double price = 78.5;
    cout << fixed << setprecision(2) << price; // 78.50
    // fixed means to use decimal notation, not scientific, setprecision(n) n is how many decimal points to be rpecise to

    //field width + padding
    int x = 7;
    cout.fill('0'); // to pad with 0s (what to put in front of your number)
    cout << setw(6) << x; // the isndie of setw is how many
}