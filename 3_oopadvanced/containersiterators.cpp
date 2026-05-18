/**
 * STL is a standard template library - a built in C++ libary of ready made data structures and algorithms. fector comes from it
 */

 /**
  * vector - dynamic array, random access via [] or at()
  * list is a doubly linked list.S equential, no random access
  * set - sorted, no publicates, no random access, cant change value once added
  * multiset, sorted,a llowes duplicates, no random access, cant chnage value once added
  * map - key/value parirs, keys must be unique
  * multimap, key/value pairs, keys do not beed to be unique
  * pair - connects two itemsinto one object. used by map/multimap
  * 
  * set = sorted, unique
  * multiset = sorted, nonunique
  * map = dictionary, unique keys
  * multimap = dictionary, duplicate keys ok
  * list = linked list (no random access)
  * vector = dynamic array(random access)
  */

#include <vector>
#include <set>
#include <list>
#include <map>
#include <utility> // for pairs
using namespace std;

int main(){
    set<int> mySet = {10,20,30,40,20}; // 10 20 30 40
    // duplicates are removed and auto sorted
    mySet.insert(25);
    mySet.size(); // number of elements
    mySet.count(10); // 1 if it exists, 0 if not, returns boolean
    mySet.erase(20); // gets rid of element 20

    map<string, int> ages;
    ages["Alice"] = 25;
    ages["Bob" ] = 20;
    //auto sorts key alphabetically
    ages["Alice"]; //25
    ages.count("Bob"); // 1 if key exists
    ages.erase("Bob"); //
    /**
     * eacg entry is a pair
     * pair of key and value
     * pair<key, value>
     */
    
     /**
      * ITERATORS
      * iterator is a generalization of a poijnter for containers
      * used for container classes
      * generalization of a poineter for containers
      */
    vector<int> v = {10,20,30};

    //iterator veclaration
    //vector<int>::iterator it = v.begin();
    //              ^^type      ^^ points to first element

    //use like a p pointer
    // *it; // 10 - dereference to get the value
    // ++it; // advance to next element, now it's the nex elemenet 20
    //it->member; // for containers of objects;

    /**
     * iterator types
     */

    //  //forward iterator - goes from begin to end
    //  vector<int>::iterator it = v.begin();
    //  while(it != v.end()){
    //     cout << *it << endl;
    //     ++it;
    //  }

    //  //reverse iterator - goes rbegin() to rend()
    //  while(rit != v.rend()){
    //     cout << *rit << endl;
    //     **rit;
    //  }
    // //const iterator - read only
    // vector<int>::const_iterator cit = v.begin();
}