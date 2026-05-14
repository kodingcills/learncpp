#include <iostream>
using namespace std;

class DynArray{
    private:
        int* m_data;
        int m_capacity;
        int m_size;
    public:
        DynArray(int initialCapacity): m_capacity(initialCapacity){
            m_size = 0;
            m_data = new int[m_capacity];
        }

        ~DynArray(){
            delete[] m_data;
            m_data = nullptr;
        }

        DynArray(const DynArray& other){
            m_capacity = other.m_capacity;
            m_size = other.m_size;

            delete[] m_data;
            for(int i = 0; i < m_size; i++){
                m_data[i] = other.m_data[i];
            }
        }   

        DynArray& operator=(const DynArray& other){
            if (this==&other){
                return *this;
            }

            delete[] m_data;

            m_capacity = other.m_capacity;
            m_size = other.m_size;

            for(int i = 0; i < m_size; i++){
                m_data[i] = other.m_data[i];
            }
            return *this;
        }
        
        void PushBack(int val){
            if(m_capacity==m_size){
                m_capacity*=2;
            }
            m_data[val] = val;
            val++;
        }

        void PopBack(){
            if(m_size!=0){
                m_size--;
            }else{
                cout << "Empty" << endl;
            }
        }

        void RemoveAt(int index){
            if(index<0 || index>=m_size){
                cout << "Invalid index" << endl;
            }else{
                for(int i = index; i < m_size-1; i++){
                    m_data[i] = m_data[i+1];
                }
                m_size--;
            }
        }

        int GetSize() const{return m_size;}
        int getCapacity() const{return m_capacity;}
        
        int At(int index) const{return m_data[index];}

        void Print() const{
            for(int i = 0; i <m_size; i++){
                cout << i << " " << m_data[i] << endl;
            }
        }
}; 

int main(){
    DynArray a(2);
    a.PushBack(1);
    a.PushBack(2);
    
    a.PushBack(3);
    a.PushBack(3);
    a.PushBack(3);

    cout << a.GetSize() << " " << a.getCapacity() << endl;
    a.RemoveAt(1);
    a.Print();
    a.PopBack();
    a.PopBack();
    a.Print();
    DynArray b(a);
    b.PushBack(5555);
    b.Print();
    a.Print();

    DynArray c(22);
    c=a;
    c.PushBack(222);
    c.Print();
    return 0;
}