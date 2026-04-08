#include <iostream>
using namespace std;

class Student{
    private:
        string m_name;
        double m_gpa;
    public:
        Student(string s, double gpa) : m_name(s), m_gpa(gpa){}
        string GetName() const{
            return m_name;
        }
        double GetGPA() const{
            return m_gpa;
        }
        void Print() const{
            cout << "Name: " << m_name << " GPA: " << m_gpa << endl;
        }
};

class Classroom{
    private:
        Student ** m_students; // dynamic array of Student POINTERS
        //**  is pointer to a pointer, m_students is a dynamic arry, but instead of holding the Student objects, it holds the memory addresses of teh studnets
        /**
         * Student * m_students = new Student[30] means the comptuer has to build 30 students immediatel,y they have to exist right away
         * Studnet ** m_students = new Student*[3] buids 3 empty chairs to be filled in later, so you can have 5 students but hte capacity of 30
         * Without the 2nd pointer, you'd have fake garbage students filling in the slots
         */
        // Studnet * m_students // array of objects
        // Student ** m_list // students all over the heap
        int m_capacity;
        int m_count;
    public:
        Classroom(int capacity){
            m_students = new Student*[capacity]; // create the array that holds the pointers, if you create an array of Student*, the new operator returns a pointer ot the first element, which is a Studnet**, 
            m_capacity = capacity;
            m_count = 0;
        }

        ~Classroom(){
            // free each student object individually, this is when you have a dynamic array of pointers **
            for(int i = 0; i < m_count; i++){
                delete m_students[i]; // free each student object
                m_students[i] = nullptr;
            }
            delete[] m_students;
            m_students = nullptr;
        }

        //copy constructor
        Classroom(const Classroom & other){
            m_capacity=other.m_capacity;
            m_count = other.m_count;
            m_students = new Student*[m_capacity]; 
            for(int i = 0; i < m_count; i++){
                // m_students[i] = other.m_students[i]; //. this copies the address, both classrooms poin tto teh same studnets, this is a copy constructor, it shuodlnt do that, you need to create new student objects
                m_students[i] = new Student(*other.m_students[i]); // dereferences to get the Studnet object, passes it to copy constructor
                //Student has no pointer memebers so compiler's default copy is filne
            }
        }

        //copy assignment operator
        Classroom & operator=(const Classroom& other){
            // self guard
            if(this == &other){
                return *this;
            }
            //free old
            for(int i = 0; i < m_count; i++){
                delete m_students[i]; // free each student object
                m_students[i] = nullptr;
            }
            delete[] m_students;
            m_students = nullptr;
            //deep copy
            m_capacity = other.m_capacity;
            m_count = other.m_count;
            m_students = new Student*[m_capacity];
            for(int i = 0; i < m_count; i++){
                m_students[i] = new Student(*other.m_students[i]);
            }
            return *this;
        }

        bool AddStudent(string name, double gpa){
            if(m_count == m_capacity){
                return false;
            }else{
                m_students[m_count] = new Student(name, gpa);
                m_count ++;
                return true;
            }

        }

        void Print() const{
            for(int i = 0; i < m_count; i++){
                 m_students[i]->Print(); // call print method since Student* is a pointer, call method use-> 
            }
        }

        int GetCount() const{
            return m_count;
            
        }
        int GetCapacity() const{
            return m_capacity;
        }
};