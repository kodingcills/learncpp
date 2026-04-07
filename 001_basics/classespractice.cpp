#include <iostream>
using namespace std;

class DynArray{
    private:
        int * data;
        int capacity;
        int size;
    public: 
        DynArray(int initialCapacity){
            data = new int[initialCapacity];
            capacity = initialCapacity; // heap memory allocated = need desctructor
            size = 0; // nneds a destrctir because the heap  is allocated in the constructor. Destructor is basically hte destroy() function
           
        }

        /**
         * THE BIG THREE
         *  Copy constructor, descructor, copy assignment operator
         * wheneve the class owns heap memory, need all 3 of these
         * 
         * Copy Constructor = called when the object is created from another object
         * 
         * DynArray b = a // copy construction
         * void f(DynArray x){
         *  = pass by value (triggers copy constructor bc copy constructor passses by value, pass by value passes a copy of it)
         * }
         */

         DynArray(const DynArray& other){
            capacity = other.capacity;
            size = other.size;
            data = new int[capacity]; // new independent allocation of ccapacity of the other

            for(int i = 0; i < size; i ++){
                data[i] = other.data[i]; // copies the actual value of it
            }
         }

        //Copy assignment operator = called when assigning one existing object to another

        //trigers on DynArray a(3), b(5);
        // a=b // assignment b already exists, this is not a constructor, so copy assignment operator is called because a is being assignment an already existing object
        DynArray& operator=(const DynArray& other){ // this is referencing the 
            if(this == &other){
                return *this; // self-assignment fuard
            } // checks if memory address of current object (this) is the same as the address of the one we are copying from the &other, this is a pointer to the current object


            delete[] data; // free what's currebtly owened

            capacity = other.capacity;
            size = other.size;
            data = new int[capacity];
            for(int i = 0; i < size; i ++ ){ 
                data[i] = other.data[i];

            }
            return *this; // returns reference to sefl
        }
        /**
         * SYNTAX BREAKDOWN
         * DynArray& = returns a reference to the object operator itself, this allows chaining
         * operator= is the funcion name, the compiler looks for hte function with operator
         * cont DynArray& other = object on the right hand side of the equals sign, as in the parameter for the argument to be passed through
         */

        ~DynArray(){
            delete[] data; // heap memory freed
            data = nullptr;
            capacity = 0;
            size = 0;
        }

        void append(int value){
            if(capacity == size){
                capacity *=2;
                int * temp = new int[capacity];
                for(int i = 0; i < size; i++ ){
                    temp[i] = data[i];
                }
                delete[] data;
                data = temp;
            }
            data[size] = value;
            size ++;
        }

        void removeAt(int index){
            if(index >= size || index < 0){
                cout <<"Invalid index";
            }else{
                for(int i = index; i < size-1; i++){
                    data[i] = data[i+1];
                }
                size --;
            }
        }

        void printArr(){
            for(int i = 0; i < size; i ++){
                cout << "[" << i << "]" << ": " << data[i];
            }
        }

        int getSize(){
            return size;
        }
        int getCapacity(){
            return capacity;
        }

};


int main() {
    DynArray a(3);
    DynArray b(4);

    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.append(5);

    a.printArr();
    
    b.append(1);
    b.append(2);
    b.append(3);
    b.append(4);
    b.append(5);

    b.printArr();

    a.removeAt(3);
    a.printArr();

    b.removeAt(2);
    b.printArr();

    DynArray c = a; //(copy construction) when you initialize a new object to an already existing one
    DynArray d(2); d = a; //(copy assignment) when you assign an already existing one to an already existing one

    c.append(1);
    c.append(2);
    c.append(3);
    c.append(4);
    c.append(5);

    c.printArr();

    d.append(1);
    d.append(2);
    d.append(3);
    d.append(4);
    d.append(5);

    d.printArr();
}