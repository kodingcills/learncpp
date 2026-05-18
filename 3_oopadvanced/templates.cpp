#include <iostream>
using namespace std;
//overloaded fucntions same logic different typ4s
int max(int a, int b){
    return (a>b) ? a : b;
}

double max(double a, double b){
    return(a>b) ? a : b;
}

string max(string a, string b){
    return (a>b) ? a : b;
}

/**
 * templates are same body, only type cahnges. tenpkates let you write it once ghen the compiler generates the correct version automatically based on the data typ you pass in
 */

template <class T>
T max(const T& a, const T& b){
    return (a>b) ? a: b;
}
/**
 * template - blueprint for enerationg functions or calsses for any type
 * type parameter - is the placeholder type, named T and taking the address of it &
 * instantiation - when the compiler generates actual code from the template for a specific type max(4,7) instantiates max<int>
 * multiple type parameteres
 * template <class T, class V> two independent type placeholders
 * template <class T> prefix that tells the compiler T is a generic type, class here doens't mean a C++ class it means "any type" you can aslo write tynemae T
 */

template <class T>
T functionName(T parameter){
    //use t like any type
}

template <class T>
void SwapVals(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

/**
 * compiler figures out T automatically
 * int x=3, y=7;
 * 
 * SwapVals(x, y); T = int
 * string s1="hi", s2="hello";
 * SwapVals(s1, s2)l // T = string
 */


//templates classes
template<class T>
class Box{
    private:
        T m_value;
    public:
        Box (T value): m_value(value){}
        T GetValue() const{
            return m_value;
        }
        void SetValue(T value){
            m_value = value;
        }
};

/**
 * Box<int> intBox(42); // integer
 * Box<string> strBox("hello") // string
 * Box<double> doubleBox(42.2) // double
 * intBox.GetValue() // 42
 * strBox.GetValue() // hello
 * doubleBox.GetValue(42.2)
 */

//multiple type parameters
template<class T, class V>
class Pair{
    private:
        T m_first;
        V m_second;
    public:
        T GetFirst() const{ return m_first; }
        T GetSecond() const{ return m_second; }
};

/**
 * Pair<string, int> p("aaa", 13) // string, int
 * p.GetFirst() // return string aaa
 * p.GetSecond() // return int 13
 * Pair<double, string> v(13.2, "aaa") // double, string
 * v.GetFirst() // return double 13.2
 * v.GetSecond() // return string aaa
 */

 //templates + scope resolution when the fucjtion definitions are outside of where the function prototypes are in the class definition

template<class T>
class Box{
    public:
        Box(T value);
        T GetValue() const;
};

template<class T>
Box<T>::Box(T value) : m_value(value){}

template<class T>
T Box<T>::GetValue() const{return m_value;}

/**
 * separate compilation fenerally works except when using templates
 * when the compiler compiles box.cpp it doesnt know what tyoe T will be yet, it can't eneratge code without knowing the type, so you have to put both delcaration and defin9tion in the .h file. templates cant be split acaross .h adn .cpp the normal way
 */

int main() {
    // Your code goes here
    
    return 0;
}