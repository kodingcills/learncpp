#include <stack>
using namespace std;
bool parseParent(char array[], int n){
	stack<char> aStack;
	//To be implemented
        for (int i = 0; i < n; i++) {
        if (array[i] == '(') {
            // push onto stack tow ait for its match
            aStack.push(array[i]);
        } else if (array[i] == ')') {
            // when no matchibng open parantheses
            if (aStack.empty()) {
                return false;
            }
            // pop matching open parantheses
            aStack.pop();
        }
    }
    // empty stack is returned when all () are matched, non-empty means there are still unmatched open () 
    return aStack.empty();
}

