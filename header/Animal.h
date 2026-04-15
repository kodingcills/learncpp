/**
 * Why split into files
 * When your class grows beyond a toy example, you split into 3 files
 * 
 * Animal.h -> class declaration (tells what will be in it)
 * Animal.cpp -> class definition (implements)
 * main.cpp -> driver that uses it
 * contains only member variables and signatures, no definitions
 * 
 * they exist because if the driver file main.cpp includes if 2 class definitions use the same header file, there will be compile errors because it was already declared one
 */

 #ifndef ANIMAL_H //  header guard, means if not defined ANIMAL H
 #define ANIMAL_H // then define it

//essentially just the regular cpp file but with the function signatures and no implementation, an the header guards
#include <iostream>
#include <string>
using namespace std;
class Animal{
    public:
        Animal(string name, int age);
        virtual void Speak() const = 0;
        virtual ~Animal();
        string GetName() const;
    private:
        string m_name;
        int m_age;
};
#endif // end the if

