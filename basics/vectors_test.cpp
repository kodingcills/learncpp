#include <iostream>
#include <vector>
using namespace std;

class Roster{
    public:
        Roster(string course, int maxSize) : m_course(course), m_maxSize(maxSize){
        }

        bool AddStudent(string name){
            if((int)m_names.size() < m_maxSize){
                m_names.push_back(name);
                return true;
            }else{
                return false;
            }
        }

        bool RemoveStudent(string name){
            for(int i = 0; i < (int)m_names.size(); i++){
                if(m_names.at(i) == name){
                    m_names.erase(m_names.begin()+i);
                    return true;
                }
            }
            return false;
        }

        void Print() const{
            cout << "Course name: " << m_course << endl;
            for(int i = 0; i < (int)m_names.size(); i++){
                cout << "Student " << i+1 << ": " << m_names.at(i) << endl;
            }
        }

        int GetSize() const{
            return (int)m_names.size();
        }

        string GetCourse() const {
            return m_course;
        }

    private:
        vector<string> m_names; // vector of student names
        string m_course; // course name
        int m_maxSize; // max students allows
};

int main(){
    Roster r("math", 3);
    r.AddStudent("a");
    r.AddStudent("b");
    r.AddStudent("c");
    r.AddStudent("d");

    r.Print();

    r.RemoveStudent("d");
    r.Print();
}
    