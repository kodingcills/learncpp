#include <iostream>
#include <string>
using namespace std;

enum Priority {LOW=1, MEDIUM=5, HIGH=10, CRITICAL};

class Task{
    private:
        string m_title;
        Priority m_priority;
    public:
        Task(string title, Priority priority): m_title(title), m_priority(priority){}

        void Print() const{
            cout << m_title << ": ";
            switch(m_priority){
                case(LOW):
                    cout << "Low" << endl;
                    break;
                case ( MEDIUM ):
                    cout << "Medium" << endl;
                    break;
                case(HIGH):
                    cout << "High" << endl;
                    break;
                case(CRITICAL):
                    cout << "critical" << endl;
                    break;
            }
        }

        bool operator>(const Task& other) const{
            return m_priority > other.m_priority;
        }

        Priority GetPriority() const{
            return m_priority;
        }
};

int main() {
    // Your code goes here
    Task a("a", LOW);
    Task b("b", HIGH);
    Task c("c", CRITICAL);

    if(a>c){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    cout << CRITICAL << endl;
    return 0;
}