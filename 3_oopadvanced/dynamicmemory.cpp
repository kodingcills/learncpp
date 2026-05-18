#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Hole{
    private:
        int m_number;
        int m_yardage;
        int m_par;
    public:
        Hole(int number, int yardage, int par): m_number(number), m_yardage(yardage), m_par(par){}
        int GetNumber() const{return m_number;}
        int GetYardage() const{return m_yardage;}
        int GetPar() const{return m_par;}
};

class GolfCourse{
    private:
        string m_name;
        string m_address;
        vector<Hole*> m_holes;
    public:
        GolfCourse(string name, string address): m_name(name), m_address(address){}
        GolfCourse(){
            m_name = "default";
            m_address = "default";
        }
        string GetName() const{return m_name;}
        string GetAddress() const{return m_address;}
        void SetName(string name){
            m_name = name;
        }
        void SetAddress(string address){
            m_address = address;
        }
        void AddHole(Hole* h){
            m_holes.push_back(h);
        }
        //overloaded function, same thing but instead of insertinh a hole hobject you pass in the number, yardage, par that comes with making the hole
        void AddHole(int num, int yar, int par){
            m_holes.push_back(new Hole(num, yar, par));
        }

        ~GolfCourse(){
            for(int i = 0; i < (int)m_holes.size(); i++){
                delete m_holes.at(i);
            }
            m_holes.clear();
        }
        GolfCourse(const GolfCourse& other){
            m_name = other.m_name;
            m_address = other.m_address;
            
            for(int i = 0; i < (int)other.m_holes.size(); i++){
                m_holes.push_back(new Hole(*other.m_holes.at(i)));
            }
        }

        GolfCourse& operator=(const GolfCourse& other){
            if(this==&other){
                return *this;
            }

            for(int i = 0; i < (int)m_holes.size(); i++){
                delete m_holes.at(i);
            }

            m_name = other.m_name;
            m_address= other.m_address;

            for(int i = 0; i < (int)other.m_holes.size(); i++){
                m_holes.push_back(new Hole(*other.m_holes.at(i)));
            }
            return *this;
        }
};

int main(){
    GolfCourse g("a", "123");
    for(int i = 0; i < 18; i++){
        g.AddHole(i, 5, 25);
    }
    GolfCourse b(g);
    GolfCourse c;
    c=b;
}