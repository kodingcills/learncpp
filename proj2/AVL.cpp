/**
Tiffany McCormick
CMSC341 SU 26
WC51050
AVL.cpp implements insertion, removal, rotations, traversal, and the other logic declared in AVL.h for an AVL tree
*/

#include "AVL.h"

using namespace std;

AVLTree::AVLTree() {
    m_root = nullptr;
    m_size = 0;
}

//deallocate every node with a postorder traversal
AVLTree::~AVLTree() {
    clearTree(m_root);
    m_root = nullptr;
    m_size = 0;
}

//delete both child subtrees before deleting their parent
void AVLTree::clearTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    clearTree(node->left);
    clearTree(node->right);
    delete node;
}

//insert a unique key, balance every ancestor on the way back up, and return the node that was created
Node* AVLTree::insert(int key) {
    Node* inserted = nullptr;
    m_root = insertNode(m_root, key, inserted);

    //a nullptr means the key was already in the tree
    if (inserted != nullptr) {
        m_size++;
    }
    return inserted;
}

//return the possibly new root of this subtree after insertion and balancing
Node* AVLTree::insertNode(Node* node, int key, Node*& inserted) {
    if (node == nullptr) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 0;
        inserted = newNode;
        return newNode;
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key, inserted);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key, inserted);
    } else {
        //duplicate keys do not change the tree
        return node;
    }

    return balance(node);
}

//remove the key when present; the required public return value is nullptr after deletion
Node* AVLTree::remove(int key) {
    if (search(key) == nullptr) {
        return nullptr;
    }

    m_root = removeNode(m_root, key);
    m_size--;
    return nullptr;
}

/**
removeNode returns the possibly new root of the subtree so that the caller can rewire its child pointer
for two children, copy the inorder successor key into the target and then remove that successor from the right subtree
*/
Node* AVLTree::removeNode(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = removeNode(node->left, key);
    } else if (key > node->key) {
        node->right = removeNode(node->right, key);
    } else {
        //zero or one child, save the surviving child before freeing this node
        if (node->left == nullptr || node->right == nullptr) {
            Node* child;
            if (node->left != nullptr) {
                child = node->left;
            } else {
                child = node->right;
            }
            delete node;
            return child;
        }

        //two children, replace with the smallest key from the right subtree
        Node* successor = findMin(node->right);
        node->key = successor->key;
        node->right = removeNode(node->right, successor->key);
    }

    return balance(node);
}

//return the smallest node in a known nonempty subtree
Node* AVLTree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

//iterative BST search avoids unnecessary recursion while following only one path
Node* AVLTree::search(int key) {
    Node* current = m_root;
    while (current != nullptr) {
        if (key == current->key) {
            return current;
        }
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}

//print the requested traversal; the assignment guarantees a lowercase valid type
void AVLTree::display(string type) {
    if (type == "inorder") {
        printInorder(m_root);
    } else if (type == "preorder") {
        printPreorder(m_root);
    } else if (type == "postorder") {
        printPostorder(m_root);
    }
    cout << endl;
}

//return the number of nodes currently owned by the tree
unsigned int AVLTree::getSize() {
    return m_size;
}

//the empty subtree has height -1, making every leaf's stored height 0
int AVLTree::getHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->height;
}

//return the absolute difference between the two child subtree heights
unsigned int AVLTree::getBF(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return static_cast<unsigned int>(abs(getHeight(node->left) - getHeight(node->right)));
}

//small helper avoids using any unapproved library function such as std::max
int AVLTree::maxHeight(int leftHeight, int rightHeight) {
    if (leftHeight > rightHeight) {
        return leftHeight;
    }
    return rightHeight;
}

//recompute a node's height after one of its children changes
void AVLTree::updateHeight(Node* node) {
    if (node != nullptr) {
        node->height = 1 + maxHeight(getHeight(node->left), getHeight(node->right));
    }
}

/**
right rotation for a left-heavy subtree
the transferred subtree must be attached before either stored height is recomputed
*/
Node* AVLTree::rotateRight(Node* node) {
    Node* newRoot = node->left;
    Node* transferred = newRoot->right;

    newRoot->right = node;
    node->left = transferred;

    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

//left rotation is the mirror image of rotateRight
Node* AVLTree::rotateLeft(Node* node) {
    Node* newRoot = node->right;
    Node* transferred = newRoot->left;

    newRoot->left = node;
    node->right = transferred;

    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

/**
update the current height first, then use the signed height difference to choose LL, LR, RR, or RL repair
getBF remains the required absolute-value helper, while direction comes from comparing the child heights
*/
Node* AVLTree::balance(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    updateHeight(node);
    if (getBF(node) <= 1) {
        return node;
    }

    if (getHeight(node->left) > getHeight(node->right)) {
        //left-right case, rotate the child before rotating this node
        if (getHeight(node->left->right) > getHeight(node->left->left)) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    //right-left case, rotate the child before rotating this node
    if (getHeight(node->right->left) > getHeight(node->right->right)) {
        node->right = rotateRight(node->right);
    }
    return rotateLeft(node);
}

//print values in sorted order: left, node, right
void AVLTree::printInorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}

//print values in preorder: node, left, right
void AVLTree::printPreorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

//print values in postorder: left, right, node
void AVLTree::printPostorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->key << " ";
}

//allocate only the one vector promised by this method, then fill it recursively
vector<Node*>* AVLTree::getInorderNodes(Node* node) {
    vector<Node*>* nodes = new vector<Node*>;
    collectInorder(node, nodes);
    return nodes;
}

void AVLTree::collectInorder(Node* node, vector<Node*>* nodes) {
    if (node == nullptr) {
        return;
    }
    collectInorder(node->left, nodes);
    nodes->push_back(node);
    collectInorder(node->right, nodes);
}

//allocate one result vector and organize its node pointers in preorder
vector<Node*>* AVLTree::getPreorderNodes(Node* node) {
    vector<Node*>* nodes = new vector<Node*>;
    collectPreorder(node, nodes);
    return nodes;
}

void AVLTree::collectPreorder(Node* node, vector<Node*>* nodes) {
    if (node == nullptr) {
        return;
    }
    nodes->push_back(node);
    collectPreorder(node->left, nodes);
    collectPreorder(node->right, nodes);
}

//allocate one result vector and organize its node pointers in postorder
vector<Node*>* AVLTree::getPostordernodes(Node* node) {
    vector<Node*>* nodes = new vector<Node*>;
    collectPostorder(node, nodes);
    return nodes;
}

void AVLTree::collectPostorder(Node* node, vector<Node*>* nodes) {
    if (node == nullptr) {
        return;
    }
    collectPostorder(node->left, nodes);
    collectPostorder(node->right, nodes);
    nodes->push_back(node);
}