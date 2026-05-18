#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

/**
 * QUEUE - FIFO
 * first in, first out to be removed
 * push() adds item to back
 * pop() removes item from front
 * fornt() looks at next item up for removal
 * 
 * STACK - LIFO
 * LAST IN FIRST OUT
 * push() adds item to top of the stack as in last element
 * pop() removes item from teht op of the stack
 * top() looks at the item currently on top
 */

int main() {
    // Your code goes here
    vector<string> names = {"Alice", "Bob", "Charlie"};
    vector<string>::iterator it = names.begin();
    while(it!=names.end()){
        cout << *it << endl;
        ++it;
    }

    set<int> scores = {45,92,78,61};
    for(set<int>::reverse_iterator rit = scores.rbegin(); rit != scores.rend(); rit++){
        cout << *rit << endl;
    }

    map<string, int> inventory = {
        {"apple", 5},
        {"banana", 2},
        {"cherry", 8}
    };
    for(auto &key : inventory){
        cout << key.first << " " << key.second << endl;
    }

    /**
     * 5. 
     * a=>200
     * b=>100
     * c=>300
     */
    vector<int> v = {10,20,30};
    for(vector<int>::iterator it = v.begin(); it!= v.end(); ++it){
        cout << *it << " ";
    }

    return 0;
}