#ifndef BST_H
#define BST_H

#include <string>
#include "Node.h"
//adding in to use namespace std because a param is initialized to a string in this header file without the proper namespace qualification
using namespace std;

class BST {
private:
    // private member variables
    unsigned int m_size;
    Node* m_root;

    // private helper methods. You may add more if you wish, but be sensible

    // inserts data into the BST recursively and returns Node* of the inserted node
    Node* insertNode(Node* node, int data);
    // finds and removes data from the BST recursively and returns Node* back recursively
    Node* removeNode(Node* node, int data);
    // searches for Node containing the data and returns back its Node* pointer
    Node* searchNode(Node* node, int data) const;
   
   //recursively deletes teh nodes in the subtree rooted at said note using postorder traversal.
   void clearTree(Node* node);

   //deep-copy subtree rooted at the node using preorder traversal and return the root of the n ewly allocated copy
   Node* copyTree(Node* node) const;

   // walks left from the node and returns the node with the minimum data value associated with it in that subtree
   Node* findMin(Node* node) const;

   //return lowercase copy of the order of the tree
   string normalizeOrder(string order) const;

    /* Each of the following three methods prints out the BST in inorder, 
       preorder, and  postorder traversal respectively
    */ 
    void printInOrder(Node* node) const;
    void printPreOrder(Node* node) const;
    void printPostOrder(Node* node) const;

public:
    // Constructor
    BST();

    // Destructor
    ~BST();

    // overloaded assignment operator; creates deep copy of the rhs BST and assigns it to the lhs
    const BST& operator=(const BST& rhs);

    /* public insert and remove functions. Returns true if successful by verifying that
       a non Null pointer value is returned
    */
    bool insert(int data);
    bool remove(int data);

    // returns Node* pointer value of the node found
    Node* search(int data) const;

    /* displays all the nodes in the BST according to the order specified by the "order" 
       string parameter. The possible arguments are "inorder", "preorder", or "postorder".
       NOTE: These strings are CASE AGNOSTIC...so passing in "PoStOrDeR" for example should 
       print out the BST in postorder traversal
    */
    void displayNodes(string order);

};

#endif 


