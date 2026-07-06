#ifndef NODE_H
#define NODE_H

class Node {
private:
    int m_data;
    Node* m_left = nullptr;
    Node* m_right = nullptr;

public:
    // Constructor
    Node(const int& data);
    
    // Getters and Setters for the member variables
    int getData() const;
    void setData(const int& data);
    Node* getLeft() const;
    void setLeft(Node* left);
    Node* getRight() const;
    void setRight(Node* right);
};

#endif // NODE_H
