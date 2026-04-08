#include <iostream>
using namespace std;

class Rectangle{ // structs bundle data toether, classes bundle data and the functions that operate on it so you can control how you access it with public and private (scopes)
    private: // only accessible inside the class
        double width;
        double height;
    
    public: //accessible from anywhere
        //constructor
        Rectangle(double w, double h){
            width = w;
            height = h;
        }

        /**
         * INITIALIZATION LISTS, instea dof assigning in the cnstructor body, initialize directly
         */
        // Point(int i = 0; int j = 0) : m_x(i), m_y(j) {}

        //const on ember functions
        //all getters should be const, so the method does not modify the member variables
        int GetWidth() const{
            return width;
        }

        int GetHeight() const{
            return height;
        }

        // void setWidth(double w){ // member functions/methods
        //     width = w;
        // }

        void setWidth(double width){
            this -> width = width; // this-> width = memeber, width = parameter, this is a pointer to the current object, useful when the parameter names are the samae as hte member names
        }
        void setHeight(double h){
            height = h;
        }
        double area(){
            return width*height;
        }
};

class Buffer{
    private:
        int * data;
        int size;
    public: 
        Buffer(int s){
            size = s;
            data = new int[size]; // allocates in constructor, heap array
        }
        // destructor - runs automatically hwne an object goes out of scope, used mainly in heap memory (dynamic allocation)
        ~Buffer(){
            delete[] data; // free in destructor
            data = nullptr;
        }
    // when buffer goes out of scope, ~Buffer() fires automatically

};

/**
 * functions inside class are called member functions or methods
 * data inside is called member varia bles
 * private are member variables only acccessibly by the classes' own methods
 * public is the interdace the outside world can use outside the scope
* protected are the parent and derived (chuld) classes' situations
 */

int main() {
    Rectangle r(5.0,4.0);
    // r.width = 5; // incassessible because width is a private member
    r.setWidth(5);
    cout << r.area();
}
