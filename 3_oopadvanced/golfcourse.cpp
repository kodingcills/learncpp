#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hole{
    private:
        int m_num;
        int m_yar;
        int m_par;
    public:
        Hole(int num, int yar, int par): m_num(num), m_yar(yar), m_par(par){}
        int GetNumber(){return m_num;}
        int GetPar(){return m_par;}
        int GetYardage(){return m_yar;}
};

class GolfCourse{
    private:
        string m_name;
        string m_address;
        vector<Hole*> holes;
    public:
        GolfCourse(string name, string address): m_name(name), m_address(address){}

        GolfCourse(GolfCourse& other){
            
        }
};