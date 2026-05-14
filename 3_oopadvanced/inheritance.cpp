// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// // without inheritance — duplicated code
// class Dog  { 
//     string m_name;
//      void Eat(); 
//      void Sleep(); 
//      void Bark(); 
// };

// class Cat  { 
//     string m_name; 
//     void Eat(); 
//     void Sleep();
//     void Meow(); 
// };

// class Bird { 
//     string m_name; 
//     void Eat(); 
//     void Sleep(); 
//     void Tweet(); 
// };

// // with inheritance — shared code lives once
// class Animal { 
//     string m_name; 
//     void Eat(); 
//     void Sleep();
// };
// class Dog  : public Animal { 
//     void Bark(); 
// };
// class Cat  : public Animal { 
//     void Meow();  
// };
// class Bird : public Animal { 
//     void Tweet(); 
// };

// /**
//  * 
//  * 3 relationships
//  * is-a realtionship - Dog is-a Animal
//  * class Dog: public Animal
//  * has-a (composition) -> member object, owned entirely but only within the scope of that
//  * Car has-a Engine -> Engine m_engine; Engine dies with car
//  * has-a aggregation -> member pointer not member object, exists indpeendently
//  * Car has a Driver -> Driver* M_driver; (Driver exists on its own)
//  * 
//  * public members child can access
//  *  protected members child can access directly
//  * private members inherited but child cannot access directly, must use the parent's getterss/setters for it
//  */

// class Animal{
//     private:
//         string m_name;
//         int m_age;
//     public:
//         Animal(string name, int age): m_name(name), m_age(age){}
//         void Eat()   { cout << "nom nom" << endl; }
//         void Sleep() { cout << "zzz" << endl; }
// };
// class Dog: public Animal{
//     private:
//         //inherits m_name and m_age but isnt direclt accessible, is in the child's memory but isnt direclty acessible witohut getters/setters
//         string m_breed;
//     public:
//         //inherits xonstructor
//        // Dog(string name, int age, string breed): Animal(name,age), m_breed(breed){}

//         //can add new
//         void Bark(){
//             cout << "woof" << endl;
//         }

//         //override
//         //scope resolution operator :: is so a child can override a function ands tull use the parent
        
//         void Eat(){
//     //        Animal::Eat(); // explicitly call parent version
//             cout << "Dog eats" << endl;
//         }

//         //prints woof \n Dog eatrs

// };

// class Animal {
// public:
//     void Speak() { cout << "..." << endl; }
// };
// class Dog : public Animal {
// public:
//     void Speak() { cout << "Woof" << endl; }
// };

// int main(){
//     Animal* ptr = new Dog;  // valid — Dog is-a Animal
//     ptr->Speak();            // prints "..." — WRONG
// }
// //need to use vi4tual keyword so the pointer looks at the object and not the pointer tpye
// class Animal {
// public:
//     virtual void Speak() { cout << "..." << endl; }
//     //^^^^^^ one word changes everything
// };
// // when using virtual, the compiler looks at hte acutal object at runtime. this is called late binding/dynamic dispath becaise it's dispatching from the dyanmically allocated memoryt o look t the actual object
// int main(){
//     Animal* ptr = new Dog;  // valid — Dog is-a Animal
//     ptr->Speak();            // prints "..." — WRONG
// };

// //pure virtual classes are abstract classes where virtual class has no body and just set tot 0
// class Animal {
// public:
//     virtual void Speak() = 0;   // pure virtual — no body
//     //                    ^^^
// };

// /**
//  * Now animal is abstract
//  * Animal a; is a compile error, you cannot instantiate an instance of the object noow
//  * Animal* ptr = new Dog; // pointer to abstract is fine
//  * 
//  * Assume Animal* ptr = new Dog and ptr->Speak():
//  * void Speak() always calls Animal::Speak() it creatss an amimal
//  * virutal void Speak() callss Dog::Speak it creates an animal
//  * virtual void Speak() = 9 is abstract, so Dog::Speak must exist, its abstract so it wont create an animal
//  */


// /**
//  * 
//  * Parent* ptr = new Child();
//  * 
//  * // looking at child object through paraent lens
//  * stores diffrent tpye of children in one list, for example
//  * vector<Animal*> can have dog, cats, birds
//  * 
//  * cvirtual works because ven though virtual says its just a parent, when you call a virtual function, and calls the child cersion of it. however, you can only call the functions defined in the parent class
//  * 
//  * ChilD* ptr = new Child()
//  * looking at child object through child lenses
//  * you cna call any fucntion in parent and child class
//  */


//  // maib use is vectors to have multiple types of children in the same vector pointer class of parents


// int main() {
//     // Your code goes here
// //     vector<Animal*> shelter;
// // shelter.push_back(new Dog("A"));
// // shelter.push_back(new Cat("b"));
// // shelter.push_back(new Bird("A"));
// // shelter.push_back(new Etc("b"));

//     for(int i = 0; i < (int)(shelter.size()); i++)
// // {
// //     shelter[i]->Speak(); // calls the version of speak of whatever yype the element is
// // }  
// //     //to cleanup, do deep celan like depe copy by going thorugh each

// //     for(int i = 0; i < (int)shelter.size(); i++){
// //         delete shelter[i];
// //         shelter[i] = nullptr;
// //     }
// // return 0;

// /**
//  * ~LinkedList(){
//  *  Node* temp = m_head;
//  * while(temp!=nullptr){
//  *  Node* next = temp->m_next;
//  *  delete temp;
//  * temp = next;
//  * }
//  * }
//  */

//  //virtual destructor
//  Aimal* ptr = new dog;
// delete ptr; // virthout virtual ~Animal, only Animal fires
// ///dog never fires-> so the heap memory leaks
// }


// //any class with virtual functions needs a virtual destructo
// class Animal {
// public:
//     virtual void Speak() = 0;
//     virtual ~Animal() {}     // ← required, even empty body
// };

// class Dog : public Animal {
// public:
//     virtual void Speak() { cout << "Woof" << endl; }
//     virtual ~Dog() { /* clean up Dog's resources */ }
// };

#include <iostream>
using namespace std;

//destructor order
/**
 * construction and destruction order are in opposites
 * constriction: parent first -> child second
 * destructor: child dirst -> parent second
 * 
 * this is because the child must us ethe parent resources in its own destructor, so the parent has to be alive when the child cleans up so tha parent dies last
 */

 /**
  * what happens is the animal is born
  * then the dog is born
  * Dobg dies
  * then animal dies
  * Animal* ptr = new Dog;
delete ptr;

// without virtual destructor, the dog is born the animal is born but hte animal dies and only the parent destrucot fores so the dog's heap memory leaks
*/
/**
 * 
 * virtual functions make it so you can call the child version of that parent one dynamically
 * pure virtual oints toa. special error handling function
 * 
 * any virtual function in hte parent means you cant make an instance of that object parent
 * 
 */
class A {
public:
    A()  { cout << "A born" << endl; }
    virtual ~A() { cout << "A died" << endl; }
};
class B : public A {
public:
    B()  { cout << "B born" << endl; }
    virtual ~B() { cout << "B died" << endl; }
};
class C : public B {
public:
    C()  { cout << "C born" << endl; }
    virtual ~C() { cout << "C died" << endl; }
};

int main(){
    A* ptr = new C;
    delete ptr;
    cout << endl;
    C c;
}

/**
 * for virtual functions and virtual m ember variables
 * 
 * class Parent {
protected:
    int id; // Standard variable, no manual free needed
public:
    virtual void doWork() = 0;
    virtual void ajwdoiwd() { COUT <<DAWJODWDJAW}
    // Virtual and empty, but tells the compiler: 
    // "Always look for the Child's destructor first!"
    //thats the standard virtual sestructor
    virtual ~Parent(); 
};
 */

 /**
  * for children,you only have to implement the pure virtual abstract functions
  * standarad virtual you can abstract. if not, child will just use whats defined in the parent class
  * 
  * children dont need their own destructor unless managing their own dynamic memory
  */