#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class DynArray{
    private:
        T* m_data;  
        int m_size;
        int m_capacity;
    public:
        DynArray(int capacity): m_capacity(capacity){
            m_data = new T[m_capacity];
            m_size = 0;
        }

        ~DynArray(){
            delete[] m_data;
            m_data = nullptr;
            m_size = 0;
            m_capacity = 4;
        }

        bool insert(T val){
            if (m_size==m_capacity && val <= m_data[m_size-1]){
                return false;
            }else if(m_size==m_capacity && val > m_data[m_size-1]){
                m_size--;
            }

            int i =m_size-1;
            while(i>=0 && m_data[i] < val){
                m_data[i+1] = m_data[i];
                i--;
            }

            //insertt hte value at its correct sorted position
            m_data[i+1] = val;
            m_size++;
            return true;
        }

        void remove(int i){
            if(i < 0 || i >=m_size) {
                throw out_of_range("index out of bounds");
            }

            // Left-shift all elements after index i
            for (int j = i; j < m_size - 1; ++j) {
                m_data[j] = m_data[j + 1];
            }

            // Reduce the size since an element was removed
            m_size--;
        }

        T& operator[](int i) {
        if (i < 0 || i >= m_size) {
            throw std::out_of_range("Index out of bounds");
        }
        return m_data[i];
    }

    // const version of above
    const T& operator[](int i) const {
        if (i < 0 || i >= m_size) {
            throw std::out_of_range("Index out of bounds");
        }
        return m_data[i];
    }

    // Returns current number of elements
    int size() const {
        return m_size;
    }

    // Returns true if no elements stored
    bool empty() const {
        return m_size == 0;
    }

    // Prints all elements in order, space-separated
    void print() const {
        for (int i = 0; i < m_size; ++i) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }
};