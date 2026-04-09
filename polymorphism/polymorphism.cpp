#include <iostream>
using namespace std;

class Vehicle {
public:
// declare virtual in the parent
//the child automatically gets dynamic dispatch even without virtual in its declaration
    virtual void Drive() { cout << "Generic drive" << endl; }
    virtual void print() = 0; // pure virtual - no body, abstract class. This is when the parent has no meaningful implementation, =0 means there's no substance but hte child class must implement this
    /**
     * so if you make an object of the parent class, it'll give you an error because it's an abstract calss, but if you make an instance of the child class, it'll be fine, and pointing to an abstract is okay
     */
};

/**
 * assume Vehicle* ptr = &myCar and ptr->Drive()
 * 
 * void Drive() can create a vehicle, Vehicle::Drive() gets called
 * virtual void Drive() can create a vehicle instance, but Car::Drive() gets called if it exsts, else vehicle::Drive()
 * 
 *  virtual void Drive() = 0 so Car::Drive() must exist, because the parent function doesn't, so you must have an overloaded function
 */

/**
 * Overloading = static polymorphism
 * multiple functions have the same scope witht he same name, happens at compile time
 * ie. multiple constructors in a class
 * 
 * Overriding = dynamic polymorphism
 * happens at runtime
 * function signatures must be identical, as in the child's signature must be identical tot eh parent's, it must be marked with virtual. scope is the relationship between the parent and child class
 * 
 * if i overload the child with different pareameters, the original parent version becomes inaccessible unless you redeclare it in the child
 */

 /**
  * EXAMPLE
class Vehicle {
public:
    virtual void Move(double distance) {
        cout << "Moving " << distance << " miles" << endl;
    }
};

class Car : public Vehicle {
public:
    // adding a second parameter — trying to OVERLOAD
    virtual void Move(double distance, double speed) {
        cout << "Moving " << distance << " miles at " << speed << " mph" << endl;
    }// overloading without calling from the parent class direclty
};

int main(){
    Car c;
    c.Move(10.0, 60.0);   // ✅ works — calls Car's two-param version
    c.Move(10.0);          // ❌ compile error — Vehicle's version is GONE
}
  */

class Car : public Vehicle {
public:
    virtual void Drive() { cout << "Car drive" << endl; }
};

//a parent pointer can point to a child, but a child pointer cannot point to a parent
/**
Vehicle * ptr = new Car; // valid
Car* ptr = new Vehicle; // incalid, because a vehicle is not a car, a pointer can only point to an object that the poitner object has an is-a relationsip with, a Vehicle is Not ca car, but a car is a vehicle
 */

 /**
  * Vector of parent pointers
  * vector<Vehicle*> garage;
garage.push_back(new Car("Toyota"));
garage.push_back(new SUV("Ford"));
garage.push_back(new Jeep("Jeep"));

// call Drive() on all of them — each calls ITS OWN version
for(int i = 0; i < (int)garage.size(); i++){
    garage[i]->Drive();   // Car::Drive, SUV::Drive, Jeep::Drive
}

// clean up — must loop and delete each
for(int i = 0; i < (int)garage.size(); i++){
    delete garage[i];
    garage[i] = nullptr;
}

without virtyual, every Drive() call would print hte Vehicle::Drive()
  */

int main(){
    // Car myCar;
    // Vehicle* ptr = &myCar;  // parent pointer to child object — valid, Car is-a Vehicle
    // ptr->Drive();            // which Drive() runs? prints Vehicle::Drive() because it's a parent pointer pointing to a child object becaus it's looking at the pointer type Vehicle* nit hte actual object

    //always delete the pointer to the child oject, without thevirutal destructor only ~Vehicle() fires, causes memory leak
    // when there are virtual functions, hte deestructor must also be virtual
    /**
     * vtable
     * when ouu declare a virtual function, it adds a hidden pointer to every object, points tot eh class' virtual table which is a table of funciton pointers for all the methods
     */

    //with virtual, it focuses on the actual object, late binding/dynamic dispatch
}