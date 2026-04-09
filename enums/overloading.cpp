#include <iostream>
using namespace std;
class Money{
    private:
        int m_dollars;
        int m_cents;

    public:
        Money(int d, int m){
            m_dollars = d;
            m_cents = m;
        }

        //MEMBER FUNCTIONS
        /**
         * Left side is always *this (the calling object)
         * Right side is the parameter
         * Called as: cash 0 bills -> cash.operator-(bills)
         */
        Money operator-(const Money& other) const{
            int totalCents1 = m_dollars * 100 + m_cents;
            int totalCents2 = other.m_dollars * 100 + other.m_cents;
            int diff = totalCents1 - totalCents2;
            return Money(diff / 100, diff%100);
        }

        //would call as cash.operator==(bills)
        bool operator==(const Money& other) const{
            return m_dollars == other.m_dollars && m_cents == other.m_cents;
        }

        //would call as m1.operator>(m2)
        bool operator>(const Money& other)const{
            return (m_dollars*100+m_cents) > (other.m_dollars*100+other.m_cents);
        }

        /**
         * FREIND FUNCTIONS
         * both sides are explicit parameters, as in actually 2 parameters vs a member fucntions 1 parameter
         * lives outside the class but has access to private members
         */
        friend Money operator+(const Money&a, const Money&b);

        //<< has to be friend, left side is ostream (output file) not m oney
        // left side is an osream not a money obejct
        friend ostream& operator << (ostream & out, const Money& m);
/**
 * what CANNOT be overloaded
 * scope resolution ::
 * . dot operator
 * .* pointer to a member
 * ?: ternary operator
 * 
 * scope resolution :: dot operator . pointer to a member .* and ternary operator ?: cannot be overrloaded because they're too critical to c++ for some reason idk
 */
};

Money operator+(const Money&a, const Money&b){
    int totalCents = (a.m_dollars * 100 + a.m_cents) + (b.m_dollars*100 + b.m_cents);
    return Money(totalCents/100, totalCents%100);
}
ostream& operator<< (ostream & out, const Money& m)
{
            out << "$" << m.m_dollars << "." << m.m_cents;
            return out;
        }

// /**
//  * Member function - left side is this, right side is parameter
//  */
// bool operator>(const Shoe& other) const {
//     return this->m_size > other.m_size;
// }
// // call:
// if(shoe1 > shoe2)   // shoe1 is this, shoe2 is other

//Friend function 0 both sides are parameters, lives outside the class
/**
 * // inside class declaration:
friend bool operator>(const Shoe& s1, const Shoe& s2);

// definition outside class:
bool operator>(const Shoe& s1, const Shoe& s2) {
    return s1.m_size > s2.m_size;
}
 */
int main(){
    Money cash(700,54);
    Money bills(300,20);
    /**
     * Operators + - == > are functions wit special names, c++ calls operator+
     */
    cash = cash - bills; // without overloading, this is wrong
}