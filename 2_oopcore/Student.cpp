#include <iostream>
#include <string>
using namespace std;

// ==========================================
// 1. CLASS DECLARATION (Usually in a .h file)
// ==========================================
class Student {
public: // PUBLIC: Anyone can access these functions (The Interface)
    // Default Constructor: Takes no arguments, sets default values
    Student();

    // Overloaded Constructor: Takes arguments. 
    // We will use an Initialization List for this one!
    Student(int id, double gpa, string name);

    // Destructor: Has the ~ (tilde). Automatically called when the object is destroyed.
    // Crucial for cleaning up any dynamic memory (new/delete).
    ~Student();

    // Accessor (Getter) & Mutator (Setter)
    void Output();
    void SetGPA(double gpa);

private: // PRIVATE: Only class methods can access these (Encapsulation)
    
    int m_id;
    double m_gpa;
    
    // We make this a pointer specifically to demonstrate dynamic memory
    // and give our Destructor a job to do!
    string* m_name; 
};

// ==========================================
// 2. CLASS IMPLEMENTATION (Usually in a .cpp file)
// ==========================================

// Default Constructor Definition
// Using the Scope Resolution Operator (::) to tell C++ this belongs to Student
Student::Student() {
    m_id = 0;
    m_gpa = 0.0;
    // Dynamically allocating memory on the HEAP using 'new'
    m_name = new string("TBD"); 
}

// Overloaded Constructor with an INITIALIZATION LIST
// The list starts with the colon ':' and directly assigns values before the body runs.
// This is highly efficient and preferred in C++.
Student::Student(int id, double gpa, string name) : m_id(id), m_gpa(gpa) {
    // We still allocate the pointer inside the body
    m_name = new string(name);
}

// Destructor Definition
// Cleans up the mess we made with 'new' to prevent Memory Leaks!
Student::~Student() {
    delete m_name;     // 1. Delete the dynamically allocated memory
    m_name = nullptr;  // 2. Golden Rule: Set pointer to nullptr for safety
    
    // Just printing this so you can see exactly when it runs in the terminal
    cout << "Destructor automatically called. Memory cleaned up!" << endl;
}

Student::~Student(){
    delete m_name; // delete the dynamically allocated memory
    m_name = nullptr; // then set to nullptr
}

// A standard Mutator (Setter) with some basic validation
void Student::SetGPA(double gpa) {
    if (gpa >= 0.0 && gpa <= 4.0) {
        m_gpa = gpa;
    } else {
        m_gpa = 0.0;
    }
}

// A Facilitator/Output method
void Student::Output() {
    // We have to dereference m_name using * to print the string, not the memory address
    cout << "Student: " << *m_name << " | ID: " << m_id << " | GPA: " << m_gpa << endl;
}


// ==========================================
// 3. MAIN FUNCTION (Driver)
// ==========================================
int main() {
    cout << "--- Creating Static Objects (Stack) ---" << endl;
    
    // Calls the Default Constructor implicitly
    Student student1; 
    
    // Calls the Overloaded Constructor explicitly (utilizes the initialization list)
    Student student2(12345, 3.8, "Alice"); 

    student1.Output();
    student2.Output();

    cout << "\n--- Creating Dynamic Object (Heap) ---" << endl;
    
    // Dynamically allocating an entire Student object using 'new'
    Student* dynStudent = new Student(99999, 2.5, "Bob");
    
    // Because dynStudent is a pointer, we usually use the arrow operator (->) 
    // or dereference it first. (Wait for your prof to cover the arrow operator!)
    (*dynStudent).Output(); 
    
    // We MUST manually delete objects we created with 'new'
    delete dynStudent;
    dynStudent = nullptr;

    cout << "\n--- Program Ending ---" << endl;
    
    // Watch what happens here! When the program ends, student1 and student2 
    // fall out of scope, and their destructors are called automatically.
    return 0;
}