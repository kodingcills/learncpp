#include <iostream>
using namespace std;

/**
Binary Trees
What a tree is
a linkedlist is a chain where one node points to teh next node, a tree is a branching chain where one node points to multiple children

A tree is a fomal collection of nodes connected by edges where
One node is the root (no parent)
Every other node has exactly one parent
There are no cycles like in a circular array

Linked list:        Tree:
[A]→[B]→[C]           A
                      / \
                     B   C
                    / \
                   D   E
*/

/**
     A          ← depth 0
    / \
    B   C        ← depth 1
   / \   \
  D   E   F      ← depth 2
     /
    G            ← depth 3

Root = top node, no parent = A
Leaf/External = Node with NO children = D, G, F
Internal, node with at least one child = A, B, C, E
PArent = node directly above = B is the parent of D and E
Child = Node directly below, D and E are the children of B
Sibling = Nodes sharing the same parent, D and E are siblings
Ancestor = Any node on path to root,  A, B, E are ancestors of G
Descendent, any node in subtree below the path to the root, so D, E, G are descendants of B
Subtree, A node + all of its descendances, for example B, D, E, G form a subtree
Edge = link between parent and child, the line between A and B
*/

/**
Depth vs Height
Depth of a NODE
number of edges from the root down to teh NODE

HEIGHT of a ndoe
number of edges fro that node down to its deepst leaf

     A   height 3
    / \
    B   C   height of b 2 height of c 1
   / \   \
  D   E   F     height of d, f = 0, height of e 1
    /
    G           height 0
    root always has depth 0
*/

