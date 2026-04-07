#include <iostream>
using namespace std;

int main(){
    int x = 42;
    int* p = &x; //.& means "address of x" as in hte actual memory address of x,
                // so p now holds 0x7ffd4a2b
    /**
     * pass by value is passing ac opy of the variable, like changing the value of a variable within the function and not returning anything is pass by value
     * 
     * pass by reference is actually addressing and changing the original copy of the variable
     * using & is to pass by reference, you don't have to return it
     * 
     * void update(int n){
     *      n = 100; // does not change n
     * }
     * 
     * void update(int &n){
     *      n = 100; // directly changes n
     * }
     * 
     * pass by pointer is to pass the memory address of the variable, so passing the 0x7ffd4a2b
     * 
     * To dereference the pointer of the address to get back the value of the variable, use *
     * 
     * Pointers can be reassigned to point to different memory addresses, it's a box pointing to another variable., it is pointing to the memoru location we're working with
     */

     // & operator is the one that gives you the unary operator adn returns the memory address of the variable
     int y = 10;
     cout << y << endl;
     cout << "x is in memory location " << &y << endl;

     // Pointers and methods

     // can create pointers to point to objects of any type, including user created types, the usual way

    /**
     *  EnglishLength * ptr;
        EnglishLength L(50);
        ptr = & L; // ptr point to L;
     */

    /**POINTERS POINTING TO OBJECT WITH METHODS
     * when pointing to an object with methods, you can either
     * 1. use the * operator to reference the object fROM THE POINTER, then use the dot operator, to reference hte object from the pointer to dereference what hte ptr is pointing to before you can perform the method on it
     */
    string s = "hi";
    string * ptr = &s; // puts memory address of s in pointer box
    cout << ptr << endl; //prints memory address of s in box
    cout << (*ptr).size();  // actually dereferences it to be used;
    /**
     * OR you can use the -> operator
     */
    cout << ptr->size();

    /**
     * BASIC USE OF POINTERS
     * 
     * To declare a pointer, use the * operator,
     */
    int *ptr1; // pointer type modifier, ptr1 is a pointer to an integer
    cout << *ptr1; //in used in code, it's a dereference operator to go to the address of ptr1 andge thte vlaue located there

    // & ampersand is address-of operator
    ptr1 = &x; // give me the memory address of x, as in the whole bunch of numbers

    /**
     * PASS BY REFERECE
     * referring to actual original variable in the memory
     * Passing by reference is modifying the actual origianl variable
     */

    // void remoteControl(int &tvChannel){
    //     tvChannel=10; // Changes actual ttv channel without returning anything ,it happens instantly
    // }

    /**
     * Pass by pointer has sa similar thing in terms of what it achieves, both allow a function to access and modify the origianl variable without making ac opy
     * PASS BY POINTER
     * they go to the memory address of whatever the piinter is pointing to, then dereferences it, still modifies original
     */

    // void gpsCoordinate(int &ptr){
    //     if(ptr != nullptr){
    //         *ptr = 10; //Manually oging to the address of the variable nad changing it
    //     }
    // }

    //POINTERS IN ARRAYS
    int arr[5] = {10,20,30,40,50};
    cout << arr; // prints an address, arr IS a pointer to arr[0];
    cout << *arr; // prints 10 - same as arr[0], as in the dereferenced arr;
    cout << *(arr+1); //goes to the memory address of index 1 (arr+1 bc arr just goes to arr[0]) then dereferecnes it with the *
    cout << arr[0]; //arr[i] is the same as *(arr+i), the array name is a pointer to the first element. Sizeof lies inside the function, you're passing the pointer, not the array
    cout << &arr; // pointer to the whole array, address memory of the whole array

    /**
     * POITNER ARITHEMTIC
     */
    int arr1[5] = {10,20,30,40,50};
    int * p = arr; // p points to address of arr[0];
    cout << *p; // p prints out 10 with dereference operatorl
    p++;
    cout << *p; // p prints out 20

    //example of swap with pointers and functions
    //under the hood, refernces ARE pointers
    // void swap(int &x, int &y){ // pass by rerference
    //     //so x and y are the variables you already passed in, as in the actual values
    //     int temp = x;
    //     x = y;
    //     y = temp;
    // }
    // // call with swap(1,2)

    // void swap(int *x, int *y){ // pass by pointer
    //     int temp = *x; // dereferencing the  memory address that's passed in as an argument throught he pointer
    //     *x = *y;
    //     *y=temp;
    // }
    //call by passing in the memory address of the parameters like swap(&1,&2)
    
     /** CONCLUSION */
     int z = 42;
     int *pts = &z; // & gives addres, * means go to the address ofg the integer z and put it in tha t box, so it's not giving back the value of it. 
     cout << z << endl;
     cout << &z << endl;
     cout << pts << endl; // prints what is inside the box (memory address)
     cout << *p; // * dereference operator in an expression is the action phase (returns hte value of whats in the box)
     //*(&x) is the value kept in the location
     int num = 10;
     cout << "the vlaue of x is " << *(&x) << endl;
}