#include <iostream>
#include <vector>
using namespace std;
/**
 * copy constructor makes brand new obkect m_gardes are never initialized it holds garbage≈
 * 
 * the assignment operator operates on already existing objects, which is why it has stuff to delete
 * copy constructor = object is born (so nothing toc lean up)
 * copy assigmment operator object already is alive (Clean ip old data first)
 * 
 */
class Hole{
    private:
        int m_number, m_yardage, m_par;
    public:
        Hole(int number, int yardage, int par): m_number(number), m_yardage(yardage), m_par(par){}
        int GetNumber()const{return m_number;}
        int GetYardage()const{return m_yardage;}
        int GetPar()const{return m_par;}
};

class GolfCourse{
    private:
        string m_name;
        string m_address;
        vector<Hole*> m_holes;
    public:
        GolfCourse(){
            m_name = "A";
            m_address = "Address";
        }
        GolfCourse(string name, string address): m_name(name), m_address(address){}

        ~GolfCourse(){
            for(auto h:m_holes){
                delete h;
            }
        }

        //copy constructor
        /**
         * 1. first directly set
         * 2. then dynamically set
         * vectors
         * vector.push_back(new Object(*other.vector[i]))
         */
        GolfCourse(const GolfCourse & other){
            m_name = other.m_name;
            m_address = other.m_address;
            for(int i = 0; i < (int)other.m_holes.size(); i++){
                m_holes.push_back(new Hole(*other.m_holes[i]));
            }
        }

        GolfCourse& operator=(const GolfCourse& other){
            if(this==&other){
                return *this;
            }
            for(auto h:m_holes){
                delete h;
            }
            //clear it with .clear()
            m_holes.clear();
            m_name = other.m_name;
            m_address = other.m_address;
            for(int i =0; i<(int)other.m_holes.size(); i++ ){
                m_holes.push_back(new Hole(*other.m_holes[i]));
            }
            return *this;
        }

        string GetName() const{
            return m_name;
        }

        string GetAddress() const{
            return m_address;
        }

        void SetName(string name){
            m_name = name;
        }

        void SetAddress(string address) {
            m_address = address;
        }
        void AddHole(int number, int yardage, int par){
            m_holes.push_back(new Hole(number, yardage, par));
        }
};
int main() {
    GolfCourse gc("Augusta", "2604 Washington Road");
    for(int i = 0; i < 18; i++){
        gc.AddHole(i, 400, 4);
    }
    GolfCourse a(gc);
    GolfCourse b;
    b=a;
}