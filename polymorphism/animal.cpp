#include <iostream>
#include <vector>
using namespace std;

class Animal{
    protected:
        string m_name;
    public:
        Animal(string name): m_name(name){}
        virtual void Speak() const = 0; // pure virtual, it's actually set to 0
        virtual void Eat() const{ // virtual provides default behavior, can still create objects, child classes can either use the default code or overrride it with their own
            cout << "nom nom";
        }
        virtual ~Animal() {}
        string getName() const{
            return m_name;
        }
};

class Dog: public Animal{
    public:
        Dog(string name): Animal(name){}

        virtual void Speak() const{
            cout << "Woof! I'm" << getName() << endl;
        }

        virtual void Eat() const{
            cout << getName() << " eats kibble" << endl;
        }
};

class Cat: public Animal{
    public:
        Cat(string name) : Animal(name){}
        virtual void Speak() const{
            cout <<"Meow! I'm " << getName();
        }
};

class Bird: public Animal{
    public:
        Bird(string name) : Animal(name){}
        virtual void Speak() const{
            cout << getName() << " says tweet!" << endl;
        }

        virtual void Eat() const{
            cout <<getName() << " eats seeds" << endl;
        }
};

int main(){
    vector<Animal*> shelter;
    shelter.push_back(new Dog("dog"));
    shelter.push_back(new Cat("cat"));
    shelter.push_back(new Bird("bird"));

    for(int i = 0; i < (int)(shelter.size()); i++){
        shelter.at(i)->Speak();
        shelter.at(i)->Eat();
    }

    //Animal a("test") gives an error because, since Animal has a pure virtual class Speak(), that makes the Animal class an abstract fclass, making an isntace of an abstract class doesn't work.
}