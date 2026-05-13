#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //ifstream reads from file
    ifstream inputFile; // declare file stream of name inputFile
    inputFile.open("scores.txt"); // connect to the file

    int score;
    while (inputFile >> score) { //reads until the file ends
        cout << score << "\n";
    }

    inputFile.close(); // always close
    return 0;

    /**
     * Steps
     * 1. Include 
     *      #include <fstream>
     * 2. Declare
     *      ifstream inputFile;
     * 3. Open
     *      inputFile.open("file.txt");
     * 4. Close
     *      inputFile.close();
     */

     //ofstream writes a file instead of reads
     ofstream outputFile;
     outputFile.open("Scores.txt");
     cout << "Writing";
     outputFile.close();
}