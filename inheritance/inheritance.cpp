#include <iostream>
using namespace std;

/**
 * INHERITANCE
 * instead of rewriting code across multiple classes, classes that share the  same code acan inherit the function sform another
 */
// Without inheritance — duplicated code
class Car   { string m_make; int m_speed; void drive(); };
class Plane { string m_make; int m_speed; void drive(); };  // same stuff again

//With inheritance - shared code lives once in parent
class Vehicle{
    string m_make;
    int m_speed;
    void drive();
};

class Car : public Vehicle{
    /**
     * shares all public stuff from Vehicle, but also has car specific studd
     */
};

/**
 * 3 RELATIONSHIPS
 * is-a -> INHERITANCE
 * Car is a Vehicle -> class Car: public Vehicle
 * Studnet is-a Person -> class Student: public Person
 * Piano is-a Instrument -> class Piano: public Instrument
 * 
 * 
 * has-a (composition) -> meber object
 * Car has-a Engine -> Egine m_engine; -> that is an Engine object directly inside Car. The object directly inside Chassis can't exist without car
 * see composition as the stack and the class as the scope, the memory of the object dies witht he parent, it exists within the parent
 * 
 * has-a (aggregation) -> member pointer;
 * Car has-a Driver -> Driver* m_driver; -> pointer to external object, driver can exist independently (dynamic allocation)
 * Aggregation is a pointer to something that exists on its own
 * 
 */


class V{ // parent/base/superclass
    public: 
        V(string make, int speed) : m_make(make), m_speed(speed){}
        void Drive(){
            cout << "driving";
        }
        string GetMake() const{
            return m_make;
        }
    private:
        string m_make;
        int m_speed;
};

class C : public V{
    public: 
        C(string make, int speed, string model): V(make, speed), m_model(model){} // child class inherited private members of the parent class (make and speed) ad uses the pparent constructor to set them
        void Honk() {
            cout << "beep beep";
        }
    private:
        string m_model;
};
/**
 * What a child inherits - access rules
 * parent public
 * parent protected
 * CANNOTA CCESS DIRECTLY
 * parent protected, must go thoruhg the parent's getters and setters
 */

 /**
  * SCOPE RESOLUTION IN CHIKLD
  * when a child wants to call the parent's version of a function it has overriden
class Vehicle {
public:
    void DisplayInfo() { cout << "Vehicle info" << endl; }
};

class Car : public Vehicle {
public:
    void DisplayInfo() {
        Vehicle::DisplayInfo();   // ← calls PARENT version explicitly
        cout << "Car info" << endl;
    }
};

Important not to put Car;:DisplayInfo(), needs to be Vehicle::DisplayInfo()
  */
int main() {
    /**
     * Constructor chaining
     * 
     * when a child object is created,t he parent constructor fires first
     */
    C myCar("Toyota", 120, "Camry");
    /**
     * Order:
     * 1. V(str, int) first to set m_make and m_speed
     * 2. Car bosy executes -> sets m_model
     */

     
}