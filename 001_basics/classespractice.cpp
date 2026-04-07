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


}