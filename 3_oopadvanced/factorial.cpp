#include <iostream>
using namespace std;
// Your code goes here
/**
 * recursion - function that calls itself
 * 
 * every recursive function has 2 parts
 * int factorial(int n){
 *      if(n <=1) return 1; // base case - stops the reursion
 *      return n* factorial(n-1);  // recursive case - calls itself
 * }
 */

 //two templates of recursion
// void recursivce fucntuion - some something wiht no return
void countdown(int n){
    if(n<=0){ // base case
        cout << "LIFTOFF" << endl;
        return;
    }
    cout << n << endl;
    countdown(n-1); // recursive call
}

//value-returning recursive function that computes soemthing
int sum(int n){
    if(n<=0){
        return 0;
    }
    return n + sum(n-1);
}

/**
 * how to write recursive functiuons - the pattern
 * 1. what is the base case - the smallest input where you know the answer directly
 * 2. what is hte recursive case? how does a larger pro lem reduce to a smaller one? 
 */
int calculateSum(int n){
    if(n<=0){
        return 0;
    }
    return n + calculateSum(n-1);
}

// int power(int base, int exp){
//     if (exp==0){
//         return 1;
//     }
//     return base * power(base, exp-1);
// }


void writeVertical(int n){ 
    if(n==0){
        return;
    }
    writeVertical(n/10);
    cout << n%10 << endl;
}

int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

/**
 * what makes recursion fail
 * missed bae case - nothing to give the recursive function an indicator to stop, so it never sotps
 * base case never reached - same crash, n grows forever and never hits the base case
 */

/**
 * stack overflow - each call tkes stack memory. Deep enough recursion runs out of it, so thats why large problems use iteration instead
 */

int factorial(int n){
    if(n<=1){
        return 1;
    }
    return n* factorial(n-1);
}

int power(int base, int exp){
    if(exp==0){
        return 1;
    }
    return base * power(base, exp-1);
}

/**
 * 3. mystery(7) = mystery(5) = mystery(3) = mystery(1) = mystery(-1)
 *                7            5            3             1
 * 
 * 1
 * 3
 * 5
 * 7
 */

 int countDigits(int n){
    if(n<=10){
        return 1;
    }
    return 1 + countDigits(n/10);
 }

/**
 * mult(4) = 2*mult(3)+1 = 2*7+1 = 15
 * mult(3) = 2*mult(2)+1 = 2*3+1 = 7
 * mult(2) = 2 *mult(1)+1 = 2*1+1=3
 * mult(1) = 1
 * 
 * mult(4) = 15
 */

int main() {
    // Your code goes here
    /**
     * recursion - function that calls itself
     * 
     * every recursive function has 2 parts
     * int factorial(int n){
     *      if(n <=1) return 1; // base case - stops the reursion
     *      return n* factorial(n-1);  // recursive case - calls itself
     * }
     */

    cout << countDigits(2) << endl;
    cout << countDigits(122) << endl;
    return 0;
}