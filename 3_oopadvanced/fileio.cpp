#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream inFile; // input file stream for reading
    ofstream outFile; // outfile file stream for writing

    //reading file
    inFile.open("data.txt");

    if(inFile){
        int x;
        string name;
        inFile >> x;
        inFile >> name;
        inFile.close();
    }

    //reading lime by line
    string line;
    while(getline(inFile, line)){ // reads one full line at a time
        cout << line << endl;
    }
    inFile.close();

    ifstream file("candy.txt");
    string type, priceStr, name, amountStr;

    // while(getline(file, type, ",") && // rads until comma
    //         getline(file, priceStr, ",") &&
    //         getline(file,name, ",") &&
    //         getline(file, amountStr)){  // reads until newline bc its at teh end
    //             double price = stod(priceStr);
    //             int amount = stoi(amountStr); // string to int;
    //         } 
    // file.close();

    ofstream outFile("output.txt");
    outFile << "HELLO" << endl;
    outFile << 42 << endl;
    outFile.close();

    //getline(file, var, dleimeter)
    //stoi() string to integer stod() string to double

    
}
