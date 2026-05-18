#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Animal{
    protected:
        string m_name; 
        int m_age;
    public:
        Animal(string name, int age): m_name(name), m_age(age){}
        // need a virtual destructor no matter if its pure virtual or regular virtual
        virtual void Speak() const = 0; 
        virtual void Print() const{
            cout << "Animal: " << m_name << " Age: " << m_age << endl;
        }
        virtual ~Animal(){
            cout << "Animal destroyed" << endl;
        }
        string GetName() const{return m_name;}
        int GetAge() const{return m_age;}
};

class Dog : public Animal{
    private:
        string m_breed;
    public:
        Dog(string name, int age, string breed): Animal(name, age), m_breed(breed){}
        virtual void Speak() const{
            cout << m_name << " says: Woof!" << endl;
        }

        virtual void Print() const{
            cout << "Dog: " << endl;
            Animal::Print();
        }
};

class Cat : public Animal{
    private:
        bool m_isIndoor;
    public:
        Cat(string name, int age, bool isIndoor): Animal(name, age), m_isIndoor(isIndoor){}
        virtual void Speak() const{
            cout << m_name << " says: Meow!" << endl;
        }
        virtual void Print() const{
            cout << "Cat: " << endl;
            Animal::Print();
            cout <<  ((m_isIndoor)? "Indoor: Yes" : "Indoor: No") << endl;
        }
};

class Shelter{
    private:
        Animal** m_animals; //dynamic array of animal pointers
        int m_capacity;
        int m_count;
        string m_name;
    public:
        Shelter(string name, int capacity): m_name(name), m_capacity(capacity){
            m_animals = new Animal*[capacity];
            m_count = 0;
        }

        ~Shelter(){
            for(int i = 0; i < m_count; i++){
                delete m_animals[i];
            }
            delete[] m_animals;
        }
        
        Shelter(const Shelter& other){
            m_capacity = other.m_capacity;
            m_count = other.m_count;
            m_name = other.m_name;

            m_animals = new Animal*[m_capacity];
            for(int i = 0; i < other.m_count; i++){
                m_animals[i] = other.m_animals[i];
            }
        }

        Shelter& operator=(const Shelter& other){
            if(this==&other){
                return *this;
            }
            for(int i = 0; i < m_count; i++){
                delete m_animals[i];
            }
            delete[] m_animals;

            m_capacity = other.m_capacity;
            m_count = other.m_count;
            m_name = other.m_name;

            m_animals = new Animal*[m_capacity];
            for(int i = 0; i < m_count; i++){
                m_animals[i] = other.m_animals[i];
            }
            return *this;
        }

        bool AddAnimal(Animal * a){
            if(m_count<=m_capacity){
                m_animals[m_count] = a;
                m_count++;
                return true;
            }
            return false;
        }

        void PrintAll() const{
            for(int i = 0; i < m_count; i++){
                (*m_animals[i]).Print();
            }
        }

        void SpeakAll() const{
            for(int i = 0; i < m_count; i++){
                (*m_animals[i]).Speak();
            }
        }

        int GetCount() const{return m_count;}
        int GetCapacity() const{return m_capacity;}
};

int main(){
    Shelter s("a", 4);
    s.AddAnimal(new Dog("dog", 24, "dbreed"));
    s.AddAnimal(new Dog("dog2", 22, "dbreed2"));
    s.AddAnimal(new Cat("cat", 20, "cbreed"));
    s.AddAnimal(new Cat("cat2", 18, "cbreed2"));
    s.PrintAll();
    s.SpeakAll();
    Shelter a(s);
    a.AddAnimal(new Dog("new dog", 11, "new"));
    s.PrintAll();
    a.PrintAll();
    Shelter b("b",4);
    for(int i = 0; i < 100; i++){
        b.AddAnimal(new Dog("Dog", i, "adwdaww"));
    }
    
}