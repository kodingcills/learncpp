#include <iostream>

/**
 * STACK = Local memory, dies when the scope dies
 * HEAP = dynamic memory, lives regardless, manually have to kill it. the pointer lives on the stack, the data it points to lives on the heap
 */

 /**
        Stack                    Heap
        -----                    ----
        main()                   [    ][    ][    ]...
        int x = 5    ←auto     ^allocated by new
        int* p ──────────────→ [42]
  */

/**
 * Dynamic memory inside classes
 *WHEN TO USE : when it owns heap memory, as in a pointer is a member variable
 * When a class owns heap memory, you need 3 things
 * 1. Destructor - tilde + class name, no return type, no parameters
 * ~MyClass(); // similar to destroy() 
 * 
 * 2. COPY CONSTRUCTOR - same name as class, it is a constructor, called when the object is created from an already existing object
 * MyClass(const MyClass& other);
 * 
 * 3. COPY ASSIGNMETN OPERATOR - called when assigning one existing object to another existing object
 * - returns reference to self to enable chaining a=b=c
 * operator= is the function name
 * param: const reference to teh same calss
 * MyClass & operator=(const MyClass & other);
 * 
 * MyClass a;
 * MyClass b=a; // copy CONSDTUCTOR - b is being born and being initialized to a, a copy of a
 * MyClass c;
 * c=a; // copy ASSIGMMENT OPERATOR - c already exists, ebing set to copy a
 */

class MyClass {
    public:
        ~MyClass(){ // delete and nullify all pointers
            delete[] m_data;
            m_data = nullptr;
        }
        MyClass(const MyClass& other){ // copy constructor
            //copy primitives directly
            m_size = other.m_size;

            //allocate NEW memory never copy the pointer itself
            m_data = new int[m_size];
            //copy the values
            for(int i = 0; i < m_size; i++){
                m_data[i] = other.m_data[i];
            }
        }

        MyClass& operator=(const MyClass& other){ // copy assignment operator
            // self assignment guard, bounds checking
            if(this == &other){
                return *this;
            }
            // free memory already owned, as in delete and nullify pointers
            delete[] m_data;
            m_data = nullptr;
            // do the same as the copy constructor body
            //return dereferenced self
            m_size = other.m_size;
            m_data = new int[m_size];
            for(int i = 0; i < m_size; i++){
                m_data[i] = other.m_data[i];
            }

            return *this;
        }

    private:
        int* m_data;
        int m_size;


};


int main(){
    //single primitive
    int *p = new int; //uninitialized, tells it to go find an open spac en the heap and has the address memory of that
    int *p; // points to garbage memory allocation
    int *p = new int(); // makes p 0, value initialization
    int *p = new int(42); //initialized to 42 directly, pointing to the data memory address of 42 on the heap

    //dynamicly allocated instance of an object
    /**
     * Car *c = new Car("Honda",2020);
     * 
     * Car *c = c is a pointer, doesn't hold the value of car it holds the memory address of where it lives
     * c is stored on the stack
     * new Car("Honda",2020); 
     * new = go to the Heap and put hte Car object memoyr on there
     * 1. new operator returns the address of the memory it just grabbed on the heap
     * 2. = takes the address and stores it in c
     * 3. c points ot the specific Honda on the heap
    */

    // array
    int * arr = new int[10]; //uninitialized array of safe garbage allocatio on heap
    int * arr = new int[10](); // zero initialized array, 10 elements of 0
    int n = 10;
    int * arr = new int[n]; // n can be defined at runtime
}