/**
Tiffany McCormick
CMSC341 SU 26
WC51050
BST.cpp implements all the recursive helpers/other logic in BST.h for the binary search tree
*/

#include "BST.h"
#include <iostream>
using namespace std;


BST::BST(){
    m_root=nullptr;
    m_size=0;
}

//deallocate every node with postorder traversal
BST::~BST() {
    clearTree(m_root);
    m_root = nullptr;
    m_size = 0;
}

//deep copy rhs into this tree
/**
guard against potential self assignment, then deallocate the current tree, then rebuilt it as a preorder copy of rhs
*/
const BST& BST::operator=(const BST& rhs) {
    if (this != &rhs) {
        clearTree(m_root);
        m_root = copyTree(rhs.m_root);
        m_size = rhs.m_size;
    }
    return *this;
}

// To insert, return true if a node was actually created.
// The empty-tree case is handled here because insertNode attaches new nodes through the parent pointer and an empty tree, with no root, therefore has no parent
bool BST::insert(int data) {
    // empty tree implies that the new node becomes the root directly
    if (m_root == nullptr) {
        m_root = new Node(data);
        m_size++;
        return true;
    }

    // non-empty tree, so recurs 
    // a non-null return means a node was inserted
    Node* inserted = insertNode(m_root, data);
    if (inserted != nullptr) {
        m_size++;
        return true;
    }
    // nullptr return means the value was a duplicate, therefore nothing was inserted
    return false;
}

// This is a helper for recursive insert
/**
This returns the Node * of the inserted note, not the subtree root, so instead of reassigning child pointers on the way back up, you walk down until there is an empty slot found, attach that new node via the parent's setter, pass the new node's pointer up unchanged.
Then return nullptr if the data already exists in the tree, giving you a dupliate.
*/
Node* BST::insertNode(Node* node, int data) {
    // duplicate found, return nullptr
    if (data == node->getData()) {
        return nullptr;
    }
 
    if (data < node->getData()) {
        // left subtree
        if (node->getLeft() == nullptr) {
            // found the empty slot, socreate and attach via the parent
            Node* newNode = new Node(data);
            node->setLeft(newNode);
            return newNode;
        }
        // keep walking down, return value bubbles up unchanged
        return insertNode(node->getLeft(), data);
    } else {
        // right subtree - data > node's data
        if (node->getRight() == nullptr) {
            Node* newNode = new Node(data);
            node->setRight(newNode);
            return newNode;
        }
        return insertNode(node->getRight(), data);
    }
}

// Return tre if the value exists and was removed
/**
removeNode returns the possibly new root of the subtree
search first to see if it exists, */
bool BST::remove(int data) {
    // if the value doesn't exist, nothing to remove
    if (search(data) == nullptr) {
        return false;
    }
 
    // if the value exists, remove
    m_root = removeNode(m_root, data);
    m_size--;
    return true;
}

// removeNode returns the root of the subtree after removal so the caller can rewire the child pointer
/**
if the target node is found
if leaf, return nullptr
if only 1 child, delete it, return the child
if 2 children, copy hte in-order successor's value into this ndoe, then recursively remove the successor from the right subtree
*/

Node* BST::removeNode(Node* node, int data) {
    // check if it exists on THE TREE
    if (node == nullptr) {
        return nullptr;
    }
 
    if (data < node->getData()) {
        // if target is in the left subtree, rewire left pointer on the way back
        node->setLeft(removeNode(node->getLeft(), data));
    } else if (data > node->getData()) {
        // if target is in the right subtree,  rewire right pointer on the way back
        node->setRight(removeNode(node->getRight(), data));
    } else {
        // If found the node to remove
 
        // leaf node, return nullptr
        if (node->getLeft() == nullptr && node->getRight() == nullptr) {
            delete node;
            return nullptr;
        }
        // only a right child, return the child
        else if (node->getLeft() == nullptr) {
            Node* child = node->getRight();
            delete node;
            return child;
        }
        // only a left child, return the child
        else if (node->getRight() == nullptr) {
            Node* child = node->getLeft();
            delete node;
            return child;
        }
        // if two children
        else {
            // in-order successor is the minimum of the right subtree
            Node* successor = findMin(node->getRight());
            // overwrite this node's value with the successor's value
            node->setData(successor->getData());
            // remove the successor from the right subtree so that node is guaranteed to have at most one right child, so this resolves as another previously covered situation
            node->setRight(removeNode(node->getRight(), successor->getData()));
        }
    }
    // this node survives, so return it so the parent keeps its pointer
    return node;
}

//return the Node* holding the data or nullptr if absent
Node* BST::search(int data) const {
    return searchNode(m_root, data);
}

// BST descent
Node* BST::searchNode(Node* node, int data) const {
    // node DNE
    if (node == nullptr) {
        return nullptr;
    }
    // node associated with data
    if (data == node->getData()) {
        return node;
    }
    // descend toward the side that could contain the value
    if (data < node->getData()) {
        return searchNode(node->getLeft(), data);
    }
    return searchNode(node->getRight(), data);
}

// case sensitive printing of the tree nodes
void BST::displayNodes(string order) {
    order = normalizeOrder(order);
 
    if (order == "inorder") {
        printInOrder(m_root);
        cout << endl;
    } else if (order == "preorder") {
        printPreOrder(m_root);
        cout << endl;
    } else if (order == "postorder") {
        printPostOrder(m_root);
        cout << endl;
    } else {
        // unrecognized order string
        cout << "Invalid order: \"" << order << "\". Use \"inorder\", \"preorder\", or \"postorder\"." << endl;
    }
}

//print values in sorted order left, node, right
void BST::printInOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }
    printInOrder(node->getLeft());
    cout << node->getData() << " ";
    printInOrder(node->getRight());
}

//print values in preorder node, left, right
void BST::printPreOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }
    cout << node->getData() << " ";
    printPreOrder(node->getLeft());
    printPreOrder(node->getRight());
}

//print values in postorder left, right, node
void BST::printPostOrder(Node* node) const {
    if (node == nullptr) {
        return;
    }
    printPostOrder(node->getLeft());
    printPostOrder(node->getRight());
    cout << node->getData() << " ";
}

//delete the subtree rooted at teh node
//both children need to be freed before the parent, or you would be referencing freed memory
void BST::clearTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    clearTree(node->getLeft());
    clearTree(node->getRight());
    delete node;
}

//deep copy of the subtree rooted at the node
//Copy the root first because that lets each recursive call return a finished subtree for the new parent to use, return the root of the newly allocated copy, or nullptr for empty subtree
Node* BST::copyTree(Node* node) const {
    if (node == nullptr) {
        return nullptr;
    }
    Node* newNode = new Node(node->getData());
    newNode->setLeft(copyTree(node->getLeft()));
    newNode->setRight(copyTree(node->getRight()));
    return newNode;
}

//retrurn the node with the minimum value in the subtree rooted at the node, checking for non-null nodes is not necessary because it's only called in a non-null node case in removeNode
Node* BST::findMin(Node* node) const {
    while (node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}

// returns a lowercase copy of the input sting
string BST::normalizeOrder(string order) const {
    for (unsigned int i = 0; i < order.length(); i++) {
        if (order[i] >= 'A' && order[i] <= 'Z') {
            order[i] = order[i] + 32;
        }
    }
    return order;
}