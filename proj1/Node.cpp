/**
Tiffany McCormick
CMSC341 SU 26
WC51050
Node.cpp is the implementation of the given Node.h class that implements the gettters/setters/constructor declared in it. 
*/

#include "Node.h"

// constructor
Node::Node(const int& data): m_data(data){}

//getters and setters

int Node::getData() const { return m_data; }
void Node::setData(const int& data) { m_data = data; }

Node* Node::getLeft() const { return m_left; }
void Node::setLeft(Node* left) { m_left = left; }

Node* Node::getRight() const { return m_right; }

void Node::setRight(Node* right) { m_right = right;} 