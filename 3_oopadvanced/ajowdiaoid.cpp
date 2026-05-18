#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//1.
vector<int> readScores(){
    ifstream file("scores.txt");
    string line;
    vector<int> v;
    while(getline(file, line)){
        v.push_back(stoi(line));
    }
    file.close();
    return v;
}

/**
 * 2.
 * a) they keyword auto allows the compiler to infer a variable's type
 * b) The operator used toa ccess a namespace is the scope resolution operator ::
 * c) A named region used to organize code is called a namespace
 * d) to prevent a calss from being inherited use the keyword final
 * e) nullptr is initialized to a poibter that points to nothing
 */


/**
 * 3. 30
 */

 /**
  * 4. line 3 shoudl be Season e = Season::SUMMER; bexause the enum is a class so you need the scope reoslution operator to access the elements of the enum
  */

//5.
void readCandy(){
    ifstream file("candy.txt");
    string line;
    string type, name, amount, price;
    int intamount;
    double doubprice;
    while(getline(file, type, ',')&&
            getline(file, name, ',') &&
            getline(file, amount, ',') &&
            getline(file, price)){
                intamount = stoi(amount);
                doubprice = stod(price);
                cout << type << endl;
                cout << name << endl;
                cout << intamount << endl;
                cout << doubprice << endl;
            }   
}

int main() {
    // Your code goes here
    
    return 0;
}