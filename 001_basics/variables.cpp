#include <iostream>
#include <string> 
using namespace std;

int main() {
    // values placed directly into source cdoe are called literals
    // printing numeric value
    std::cout << 5;
    //printing double value
    std::cout << -6.7;
    //printing char
    std::cout << 'T';
    //printing boolean
    std::cout << false;

    // int, bool, double, char built into the compiler adn have fixed, low-level memory representations. they cannot grow or shrink
    int x = 3; // Integer
    double y = 2; // Floating point
    char c = 'A'; // char (single quotes)
    bool t = true; // boolean

    /**
     * String is different because it's NOT a build in type
     *    std::string
     * String is a class, user-defined type, and part of the standard library string
     * std:: string 
    */
    std::string name = "Tiffany";
    
    // 1. Fundamental Built-In Types

    /**
     * A. Integer Types
     *  short - 2 bytes
     *  int - 4 bytes
     *  long - 4 || 8 bytes
     *  long long - 8 bytes
     * 
     * Can either be
     *  signed - default
     *  unsigned - positive only
     */
    int a = 10;
    unsigned int b = 5;
    long long big = 9000000000LL;

    /**
     * What happens if unsigned int b = -5?
     * compiles, but wraps around due to modulus arithmetic
     * int is max 4 bytes, or 32 bits. So the range of the unsigned is 0-2^32-1.
     * the result of unsigned int x = -5 is -5 mod 2^32
     * = 3^32-5
     */
    unsigned int aa = -5;

    /**
     * B. Floating-Point Types
     *      float - 4 bytes ~6-7 digits
     *      double - 8 bytes ~15-16 digits
     *      long double - 8/12/16 bytes extended precision
     */
    float f = 3.14f;
    double d = 3.141592635;

    /**
     * C. Character Types
     *      char - standard cahracter
     *      signed char - small signed integer
     *      unsigned char - small unsigned integer
     *      wchar - wide characters 
     */

    // char
    char c = 'A';        // character literal
    char n = 65;         // numeric value (ASCII for 'A')
    //signed char
    signed char sc = -10;
    //unsigned char
    unsigned char uc = 250;
    //wchar_t
    wchar_t wc = L'Ω'; 

    /**
     * D. Boolean Type
     */
    bool isReady = true;

    return 0;

    // initialization
    int width {5}; // defines variable width and initialize with intiial value 5 

    // types of initialization
    int a; // default (no initializer)

    //Traditional initialization forms:
    int b = 5; // copy-initialization (set it to whatever is after the equals sign)
    return 0;
}