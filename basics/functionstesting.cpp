#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rollDice(int sides);
void rollAndPrint(int numRolls, int sides);
void fillGrid(int grid[][3], int rows);
void printGrid(int grid[][3], int rows);
bool isPalindrome(char str[], int len);

int main() {
    // Your code goes here
    srand(time(NULL));
    rollAndPrint(5,6);
    int g[3][3] = {};
    fillGrid(g, 3);
    printGrid(g, 3);

    char s1[] = "racecar";
    char s2[] = "hello";
    cout << isPalindrome(s1, 7) << endl;
    cout << isPalindrome(s2, 5) << endl;
}

int rollDice(int sides){
    int r = rand() % sides + 1;
    return r;
}

void rollAndPrint(int numRolls, int sides){
    for(int i = 0; i < numRolls; i++){
        cout << rollDice(sides) << endl;
    }
}

void fillGrid(int grid[][3], int rows){
    int temp = 1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < 3; j ++ ){
            grid[i][j] = temp;
            temp ++;
        }
    }
}

void printGrid(int grid[][3], int rows){
    for(int i = 0; i < rows; i ++ ){
        for(int j = 0; j < 3; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isPalindrome(char str[], int len){
    for(int i = 0; i < len/2; i++){
        if (str[i] != str[len-1-i]){
            return false;
        }
    }
    return true;
}