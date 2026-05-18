// named region that gorups code toa void naming conflicts
//namespaces are used to organize code and reduce naming conflicts its called a namespace

namespace MyLib{
    int add(int a, int b){ return a+b;}
    double pi = 3.14159;
}

#include <iostream>
using namespace std;

int main(){
    //without using namespace, ou need to use the scope resolution oeprator to acess things inside that namespace ::
    std::cout << "hello" << std::endl;
    std::vector<int> v;

    //with anmespace std
    cout << "hello" << endl;
    vector<int> v;

    /**
     * auto - type inference it lets the compiler infer basically guess a varialbe's type from its initializer
     *nullptr ais a pointer that doesnt point to an object and maybe intiialized to nullptr
     //constexpr its a value computed at compile time, compielr knows its 10 for exampke
     override overrides parent function in inheritance
     //final makes it so it cant be overriden final class means it cannot be inehrited from that class cannot have children

     enum class scoped enum
     */
}