#include <iostream>
using namespace std;
/**
an array is a contiguous memory, everything is gjammed together in ar wo, everything is neighbors in memory
linekdlist is scattered memory stitched together with pointers

Array:
[10][20][30][40]     ← all neighbors in memory

Linked List:
[10|•]→[20|•]→[30|•]→[40|null]
  ↑
 head
Each node lives ANYWHERE in memory.
The pointer is what connects them.
*/

//a node is the data, and the pointer ot the next node
//the list itself just hodls a pointer to the first bnode wth Node* head = nullptr;

