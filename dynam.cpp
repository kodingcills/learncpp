void update(int* p){ // this is passing a copy of the address
    p = new int(10);
}

void update(int*& p){ // this is passing by pointer reference, passing hte original pointer variable itself
    //this allows you to go to the address of where it is and change it, you are passing the pointer by reference, so modifying the original
    p = new int(10);
}