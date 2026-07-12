#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <vector>
#include <string>

// This library is only included for the use of the abs() function. You CANNOT use any other method from this library
#include <cstdlib>

using namespace std;

// don't mess with these forward declarations
class Test;
class Grader;

/* For simplicity's sake, we will use a struct for the nodes instead of class objects
   in this project. Reminder that members of a struct are by default public.
*/
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
public:
    AVLTree(); // Constructor
    ~AVLTree(); // Destructor

    // Public methods
    Node* insert(int key); // Insert a Node with a given key into the AVL tree. Return the pointer of the node inserted, and nullptr if a node with the given key value already exists in the tree
    Node* remove(int key); // Remove a Node with a given key from the AVL tree. Should return the pointer to the node removed, which should be set to nullptr after removal (so nullptr is returned)
    Node* search(int key); // Search for a key in the AVL tree and return its node pointer. Return nullptr if a node with given key value does not exist in the tree
    void display(string type); /* Print the AVL tree in whichever fashion is specified by the "type" argument (which could be either preorder, inorder, or postorder).
                                  Assume that "type" will always be lower case */
    unsigned int getSize(); // returns the current node count present in the tree

private:
    Node* m_root = nullptr; // Root node of the AVL tree
    unsigned int m_size = 0; // number of nodes in the AVL tree

    // Private methods provided in the starter file
    int getHeight(Node* node); // Get the height of a node
    unsigned int getBF(Node* node); /* compute and get the balance factor of a node (absolute value of the difference of the node's left child subtree's height
                              and the node's right child subtree's height */
    Node* rotateRight(Node* node); // Perform a right rotation about subroot
    Node* rotateLeft(Node* node); // Perform a left rotation about subroot
    Node* balance(Node* node); // Balances the subtree subrooted by "node" if it is unbalanced
    void printInorder(Node* node); // Recursive function to print inorder traversal
    void printPreorder(Node* node); // prints in preorder traversal
    void printPostorder(Node* node); // prints in postorder traversal
    vector<Node*>* getInorderNodes(Node* node); // returns one dynamically allocated vector organized in inorder fashion
    vector<Node*>* getPreorderNodes(Node* node); // returns one dynamically allocated vector organized in preorder fashion
    vector<Node*>* getPostordernodes(Node* node); // returns one dynamically allocated vector organized in postorder fashion

    // Private recursive helpers used by the public methods
    void clearTree(Node* node);
    Node* insertNode(Node* node, int key, Node*& inserted);
    Node* removeNode(Node* node, int key);
    Node* findMin(Node* node);
    void updateHeight(Node* node);
    int maxHeight(int leftHeight, int rightHeight);
    void collectInorder(Node* node, vector<Node*>* nodes);
    void collectPreorder(Node* node, vector<Node*>* nodes);
    void collectPostorder(Node* node, vector<Node*>* nodes);

    // don't mess with these friend class declarations
    friend class Test;
    friend class Grader;
};

#endif