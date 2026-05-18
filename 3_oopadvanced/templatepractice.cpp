#include <iostream>
using namespace std;

template <class T>
T minimum(T a, T b){
    return (a>b) ?  b : a;
}

template <class T>
class Stack{
    private:
        //T* means m_datra is a pointer to the very firt item in a contigupus block of T data the objects sit right next ot each other in memory inside the array itself, which an array is a pointer in itself
        /**
         * T m_data = new T*[capacity] is a 1d array of pointers
         * T* m_data = new T*[capacity] is invalid because it is a typemismatch, declaring m_data as a dsingle pointer but assigning it ot a double pointer's work
         * an array of pointers instad of an array of atual values
         * T** m_data = new T*[capacity] gives an array of pointers
         */
        T* m_data;
        int m_top;
        int m_capacity;
    public:
        Stack(int capacity): m_capacity(capacity){
            m_data = new T[m_capacity];
        }
        ~Stack(){
            delete[] m_data;
            m_data = nullptr;
        }
        //adding copy constructor and copy operator for practice
        Stack(const Stack& other){
            m_top = other.m_top;
            m_capacity = other.m_capacity;
            m_data = new T[m_capacity];
            for(int i = 0; i < m_top; i++){
                m_data[i] = other.m_data[i];
            }
        }
        Stack& operator=(const Stack& other){
            if(this==&other){
                return *this;
            }

            //delet first
            for(int i = 0; i < m_top; i++){
                delete m_data[i];
            }
            delete[] m_data;
            //then allocate
            m_top = other.m_top;
            m_capacity = other.m_capacity;
            m_data = new T[m_capacity];
            for(int i = 0; i < m_top; i++){
                m_data[i] = other.m_data[i];
            }
            return *this;
        }

        void Push(T value){
            if(m_top>=m_capacity){
                cout << "Full" << endl;
                m_capacity *=2;
                T* new_data = new T[m_capacity];
                for(int i = 0; i < m_top; i++){
                    new_data[i] = m_data[i];
                }
                delete [] m_data;
                new_data[m_top] = value;
                m_top++;
                m_data = new_data;
            }else{
                m_data[m_top] = value;
                m_top++;
            }
        }

        T Pop(){
            if(m_top==0){
                cout << "Empty" << endl;
                return T();
            }
            m_top--;
            m_data = m_data[m_top];
            return m_data[m_top];
        }

        void Print() const{
            for(int i = 0; i < m_top; i++){
                cout << m_data[i] << endl;
            }
        }
};

/**
 * error 12 should be .print()]5 shoudl be void print() { cout << m_a << "-" << m_b << endl;}
 * 3 should be public:
 */

int main() {
    // Your code goes here
    
    return 0;
}