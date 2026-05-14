#include <iostream>
#include <string>
using namespace std;

class Library{
    private:
        string m_name;
        string* m_books;
        int m_capacity;
        int m_count;
    public:
        Library(string name, int capacity) : m_name(name), m_capacity(capacity){
            m_books = new string[m_capacity];
            m_count = 0;
        }

        ~Library(){
            delete [] m_books;
            m_books = nullptr;
        }

        //must pass by reference and mark it const
        Library(const Library& other){
            m_name = other.m_name;
            m_capacity = other.m_capacity;
            m_count = other.m_count;
            // need to allocate new dat in the heap for hte new object to copy over to
            //deep copy
            m_books = new string[m_capacity];
            //deep copy every element individually with for loop
            for(int i = 0; i < m_capacity; i++){
                m_books[i] = other.m_books[i];
            }
        }

        Library& operator=(const Library& other){
            // check if its the same
            if(this == &other){
                return *this;
            }
            // step 2. delete from heap

            //clean existing memory then copy things over
            delete [] m_books;

            // step 3. direct copy over
            m_name = other.m_name;
            m_capacity = other.m_capacity;
            m_count = other.m_count;

            //step 4 deep copy
            m_books = new string[m_capacity];
            for(int i = 0; i < m_capacity; i++){
                m_books[i] = other.m_books[i];
            }
            //no setting to nullptr

            return *this;
        }

        bool AddBook(string title){
            if (m_count < m_capacity){
                m_books[m_count] = title;
                m_count++;

                return true;
            }
            return false;
        }

        void RemoveLastBook(){
            if(m_count > 0){
                m_count --;
            }else{
                cout << "Library empty" << endl;;
            }
        }

        void Print() const{
            cout << m_name << endl;
            for(int i = 0; i < m_count; i++){
                cout << i << " " << m_books[i];
            }
            cout << endl;
        }

        int GetCount() const{
            return m_count;
        }
        
        int GetCapacity() const{
            return m_capacity;
        }
};

int main(){
    Library a("Main Branch",3);
    a.AddBook("a");
    a.AddBook("b");
    a.AddBook("c");
    cout << a.AddBook("c") << endl;
    a.Print();

    Library b = a;
    b.AddBook("e");
    a.Print();
    b.Print();
    a.RemoveLastBook();
    a.RemoveLastBook();
    Library c("Temp",2);
    c=a;
    c.Print();
}