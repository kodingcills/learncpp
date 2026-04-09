#include <iostream>
using namespace std;

enum Grade{ A=4, B=3, C=2, D=1,F=0};

class Student{
    private:
        string m_name;
        double m_gpa;
        Grade m_letterGrade;
    public:
        Student(string name, double gpa) : m_name(name), m_gpa(gpa){
       m_letterGrade = (gpa >= 3.5) ? A :
                (gpa >= 2.5) ? B :
                (gpa >= 1.5) ? C :
                (gpa >= 1.0) ? D : F;
        }

        bool operator>(const Student &s) const{
            return m_gpa > s.m_gpa;
        }

        friend bool operator==(const Student& s, const Student& a);

        void Print() const {
            string letter = (m_gpa >= 3.5) ? "A" :
                            (m_gpa >= 2.5) ? "B" :
                            (m_gpa >= 1.5) ? "C" :
                            (m_gpa >= 1.0) ? "D" : "F";
            cout << "Name: " << m_name << " GPA: " << m_gpa << " Grade: " << letter << endl;
        }
};
bool operator==(const Student& s, const Student& a){
    return (s.m_letterGrade == a.m_letterGrade) ? true : false;
}

int main(){
    Student a("a", 3.4);
    Student b("b", 4.0);
    Student c("c", 1.0);

    a.Print();
    b.Print();
    c.Print();

    bool s = a == b;
    cout << s << endl;
    bool t= b > c;
    cout << t << endl;
}