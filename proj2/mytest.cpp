/**
Tiffany McCormick
CMSC341 SU 26
WC51050
mytest.cpp tests the public behavior, exact AVL structure, stored heights, balance factors, and traversal helpers
*/

#include "AVL.h"
#include <math.h>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

enum RANDOM {UNIFORMINT, UNIFORMREAL, NORMAL, SHUFFLE};
class Random {
public:
    Random(int min, int max, RANDOM type=UNIFORMINT, int mean=50, int stdev=20) : m_min(min), m_max(max), m_type(type)
    {
        if (type == NORMAL){
            m_generator = std::mt19937(m_device());
            m_normdist = std::normal_distribution<>(mean,stdev);
        }
        else if (type == UNIFORMINT) {
            m_generator = std::mt19937(10);
            m_unidist = std::uniform_int_distribution<>(min,max);
        }
        else if (type == UNIFORMREAL) {
            m_generator = std::mt19937(10);
            m_uniReal = std::uniform_real_distribution<double>((double)min,(double)max);
        }
        else {
            m_generator = std::mt19937(m_device());
        }
    }
    void setSeed(int seedNum){
        m_generator = std::mt19937(seedNum);
    }

    void getShuffle(vector<int> & array){
        for (int i = m_min; i<=m_max; i++){
            array.push_back(i);
        }
        shuffle(array.begin(),array.end(),m_generator);
    }

    void getShuffle(int array[]){
        vector<int> temp;
        for (int i = m_min; i<=m_max; i++){
            temp.push_back(i);
        }
        std::shuffle(temp.begin(), temp.end(), m_generator);
        vector<int>::iterator it;
        int i = 0;
        for (it=temp.begin(); it != temp.end(); it++){
            array[i] = *it;
            i++;
        }
    }

    int getRandNum(){
        int result = 0;
        if(m_type == NORMAL){
            result = m_min - 1;
            while(result < m_min || result > m_max)
                result = m_normdist(m_generator);
        }
        else if (m_type == UNIFORMINT){
            result = m_unidist(m_generator);
        }
        return result;
    }

    double getRealRandNum(){
        double result = m_uniReal(m_generator);
        result = std::floor(result*100.0)/100.0;
        return result;
    }

private:
    int m_min;
    int m_max;
    RANDOM m_type;
    std::random_device m_device;
    std::mt19937 m_generator;
    std::normal_distribution<> m_normdist;
    std::uniform_int_distribution<> m_unidist;
    std::uniform_real_distribution<double> m_uniReal;
};

class Test {
private:
    int m_passed;
    int m_failed;
    int m_testNum;

    void report(string name, bool passed);
    int verifySubtree(Node* node, bool& valid, int* previous, bool& hasPrevious, unsigned int& count);
    bool verifyTree(AVLTree& tree);
    bool vectorKeysEqual(vector<Node*>* nodes, const int expected[], unsigned int size);
    bool exactThreeNodeTree(AVLTree& tree, int rootKey, int leftKey, int rightKey);

public:
    Test();
    void testEmptyTree();
    void testInsertAndDuplicate();
    void testLLRotation();
    void testRRRotation();
    void testLRRotation();
    void testRLRotation();
    void testHeightAndBalanceHelpers();
    void testSearch();
    void testTraversalHelpers();
    void testRemoveMissing();
    void testRemoveLeaf();
    void testRemoveOneChild();
    void testRemoveTwoChildren();
    void testRemovalRotations();
    void testRemoveRootUntilEmpty();
    void testManyMixedOperations();
    void testDisplayVisual();
    void runAll();
    void summary();
};

Test::Test() {
    m_passed = 0;
    m_failed = 0;
    m_testNum = 0;
}

void Test::report(string name, bool passed) {
    m_testNum++;
    cout << "Test " << m_testNum << " (" << name << "): ";
    if (passed) {
        cout << "PASSED" << endl;
        m_passed++;
    } else {
        cout << "FAILED" << endl;
        m_failed++;
    }
}

/**
verify one subtree in a single inorder walk
the return value is the independently computed height, while valid records any BST order, height, or balance error
*/
int Test::verifySubtree(Node* node, bool& valid, int* previous, bool& hasPrevious, unsigned int& count) {
    if (node == nullptr) {
        return -1;
    }

    int leftHeight = verifySubtree(node->left, valid, previous, hasPrevious, count);
    if (hasPrevious && node->key <= *previous) {
        valid = false;
    }
    *previous = node->key;
    hasPrevious = true;
    count++;
    int rightHeight = verifySubtree(node->right, valid, previous, hasPrevious, count);

    int expectedHeight;
    if (leftHeight > rightHeight) {
        expectedHeight = leftHeight + 1;
    } else {
        expectedHeight = rightHeight + 1;
    }
    if (node->height != expectedHeight || abs(leftHeight - rightHeight) > 1) {
        valid = false;
    }
    return expectedHeight;
}

//check the BST property, every stored height, every AVL balance condition, and the public size
bool Test::verifyTree(AVLTree& tree) {
    bool valid = true;
    bool hasPrevious = false;
    int previous = 0;
    unsigned int count = 0;
    verifySubtree(tree.m_root, valid, &previous, hasPrevious, count);
    return valid && count == tree.m_size && count == tree.getSize();
}

bool Test::vectorKeysEqual(vector<Node*>* nodes, const int expected[], unsigned int size) {
    if (nodes == nullptr || nodes->size() != size) {
        return false;
    }
    for (unsigned int i = 0; i < size; i++) {
        if (nodes->at(i) == nullptr || nodes->at(i)->key != expected[i]) {
            return false;
        }
    }
    return true;
}

bool Test::exactThreeNodeTree(AVLTree& tree, int rootKey, int leftKey, int rightKey) {
    Node* root = tree.m_root;
    return root != nullptr && root->key == rootKey &&
           root->left != nullptr && root->left->key == leftKey &&
           root->right != nullptr && root->right->key == rightKey &&
           root->left->left == nullptr && root->left->right == nullptr &&
           root->right->left == nullptr && root->right->right == nullptr &&
           verifyTree(tree);
}

//edge case all empty-tree operations should be safe and size should begin at zero
void Test::testEmptyTree() {
    AVLTree tree;
    vector<Node*>* nodes = tree.getInorderNodes(tree.m_root);
    bool ok = tree.m_root == nullptr && tree.getSize() == 0;
    ok = ok && tree.search(12) == nullptr && tree.remove(12) == nullptr;
    ok = ok && nodes != nullptr && nodes->empty() && verifyTree(tree);
    delete nodes;
    report("empty tree behavior", ok);
}

//normal insertion returns the created pointer while a duplicate returns nullptr without changing size
void Test::testInsertAndDuplicate() {
    AVLTree tree;
    Node* first = tree.insert(40);
    Node* second = tree.insert(20);
    Node* duplicate = tree.insert(40);
    bool ok = first != nullptr && first->key == 40;
    ok = ok && second != nullptr && second->key == 20;
    ok = ok && duplicate == nullptr && tree.getSize() == 2 && verifyTree(tree);
    report("insert return values and duplicate rejection", ok);
}

void Test::testLLRotation() {
    AVLTree tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    report("LL insertion uses one right rotation", exactThreeNodeTree(tree, 20, 10, 30));
}

void Test::testRRRotation() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    report("RR insertion uses one left rotation", exactThreeNodeTree(tree, 20, 10, 30));
}

void Test::testLRRotation() {
    AVLTree tree;
    tree.insert(30);
    tree.insert(10);
    tree.insert(20);
    report("LR insertion uses a double rotation", exactThreeNodeTree(tree, 20, 10, 30));
}

void Test::testRLRotation() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(30);
    tree.insert(20);
    report("RL insertion uses a double rotation", exactThreeNodeTree(tree, 20, 10, 30));
}

//the private height and balance helpers should agree with the exact stored structure
void Test::testHeightAndBalanceHelpers() {
    AVLTree tree;
    int values[] = {30, 20, 40, 10};
    for (int i = 0; i < 4; i++) {
        tree.insert(values[i]);
    }
    Node* leaf = tree.search(10);
    Node* root = tree.m_root;
    bool ok = tree.getHeight(nullptr) == -1 && tree.getHeight(leaf) == 0;
    ok = ok && tree.getHeight(root) == 2 && tree.getBF(root) == 1;
    ok = ok && tree.getBF(leaf) == 0 && tree.getBF(nullptr) == 0;
    report("height and balance-factor helpers", ok && verifyTree(tree));
}

void Test::testSearch() {
    AVLTree tree;
    int values[] = {50, 25, 75, 10, 30, 60, 90};
    bool ok = true;
    for (int i = 0; i < 7; i++) {
        tree.insert(values[i]);
    }
    for (int i = 0; i < 7; i++) {
        Node* found = tree.search(values[i]);
        ok = ok && found != nullptr && found->key == values[i];
    }
    ok = ok && tree.search(-1) == nullptr && tree.search(1000) == nullptr;
    report("search finds present keys and rejects missing keys", ok && verifyTree(tree));
}

//test all three required vector helpers against the exact traversal order
void Test::testTraversalHelpers() {
    AVLTree tree;
    int values[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++) {
        tree.insert(values[i]);
    }
    int inorderExpected[] = {10, 20, 30, 40, 50, 60, 70};
    int preorderExpected[] = {40, 20, 10, 30, 60, 50, 70};
    int postorderExpected[] = {10, 30, 20, 50, 70, 60, 40};
    vector<Node*>* inorder = tree.getInorderNodes(tree.m_root);
    vector<Node*>* preorder = tree.getPreorderNodes(tree.m_root);
    vector<Node*>* postorder = tree.getPostordernodes(tree.m_root);
    bool ok = vectorKeysEqual(inorder, inorderExpected, 7);
    ok = ok && vectorKeysEqual(preorder, preorderExpected, 7);
    ok = ok && vectorKeysEqual(postorder, postorderExpected, 7);
    delete inorder;
    delete preorder;
    delete postorder;
    report("inorder, preorder, and postorder vector helpers", ok);
}

void Test::testRemoveMissing() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(5);
    unsigned int oldSize = tree.getSize();
    Node* result = tree.remove(999);
    bool ok = result == nullptr && tree.getSize() == oldSize;
    ok = ok && tree.search(10) != nullptr && tree.search(5) != nullptr;
    report("removing a missing key leaves tree unchanged", ok && verifyTree(tree));
}

void Test::testRemoveLeaf() {
    AVLTree tree;
    int values[] = {20, 10, 30, 5};
    for (int i = 0; i < 4; i++) {
        tree.insert(values[i]);
    }
    Node* result = tree.remove(5);
    bool ok = result == nullptr && tree.search(5) == nullptr && tree.getSize() == 3;
    report("remove a leaf", ok && verifyTree(tree));
}

void Test::testRemoveOneChild() {
    AVLTree tree;
    int values[] = {30, 20, 40, 10};
    for (int i = 0; i < 4; i++) {
        tree.insert(values[i]);
    }
    tree.remove(20);
    bool ok = tree.search(20) == nullptr && tree.search(10) != nullptr && tree.getSize() == 3;
    report("remove a node with one child", ok && verifyTree(tree));
}

void Test::testRemoveTwoChildren() {
    AVLTree tree;
    int values[] = {50, 30, 70, 20, 40, 60, 80, 55, 65};
    for (int i = 0; i < 9; i++) {
        tree.insert(values[i]);
    }
    tree.remove(70);
    bool ok = tree.search(70) == nullptr && tree.getSize() == 8;
    ok = ok && tree.search(60) != nullptr && tree.search(80) != nullptr;
    report("remove a node with two children", ok && verifyTree(tree));
}

//removals can create each direction of imbalance just like insertions can
void Test::testRemovalRotations() {
    AVLTree leftHeavy;
    int leftValues[] = {4, 2, 6, 1, 3, 5, 7};
    for (int i = 0; i < 7; i++) {
        leftHeavy.insert(leftValues[i]);
    }
    leftHeavy.remove(7);
    leftHeavy.remove(6);

    AVLTree rightHeavy;
    int rightValues[] = {4, 2, 6, 1, 3, 5, 7};
    for (int j = 0; j < 7; j++) {
        rightHeavy.insert(rightValues[j]);
    }
    rightHeavy.remove(1);
    rightHeavy.remove(2);

    bool ok = verifyTree(leftHeavy) && verifyTree(rightHeavy);
    report("removal rebalances left-heavy and right-heavy trees", ok);
}

//repeatedly remove the current root, including two-child, one-child, leaf, and final empty cases
void Test::testRemoveRootUntilEmpty() {
    AVLTree tree;
    int values[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    for (int i = 0; i < 15; i++) {
        tree.insert(values[i]);
    }

    bool ok = true;
    while (tree.m_root != nullptr) {
        int rootKey = tree.m_root->key;
        unsigned int oldSize = tree.getSize();
        tree.remove(rootKey);
        ok = ok && tree.search(rootKey) == nullptr;
        ok = ok && tree.getSize() + 1 == oldSize && verifyTree(tree);
    }
    ok = ok && tree.getSize() == 0;
    Node* reused = tree.insert(99);
    ok = ok && reused != nullptr && tree.m_root == reused && verifyTree(tree);
    report("remove roots until empty, then reuse tree", ok);
}

//larger deterministic workload checks invariants after every insertion and removal
void Test::testManyMixedOperations() {
    AVLTree tree;
    Random random(1, 200, SHUFFLE);
    random.setSeed(341);
    vector<int> values;
    random.getShuffle(values);
    bool ok = true;

    for (unsigned int i = 0; i < values.size(); i++) {
        tree.insert(values[i]);
        ok = ok && verifyTree(tree);
    }
    for (unsigned int i = 0; i < values.size(); i += 2) {
        tree.remove(values[i]);
        ok = ok && tree.search(values[i]) == nullptr && verifyTree(tree);
    }
    for (unsigned int i = 1; i < values.size(); i += 2) {
        ok = ok && tree.search(values[i]) != nullptr;
    }
    ok = ok && tree.getSize() == 100;
    report("200 shuffled inserts and 100 mixed removals", ok);
}

//visual check supplements the automatic traversal-helper test
void Test::testDisplayVisual() {
    AVLTree tree;
    int values[] = {20, 10, 30};
    for (int i = 0; i < 3; i++) {
        tree.insert(values[i]);
    }
    cout << "\nVisual display check:" << endl;
    cout << "inorder expected:   10 20 30" << endl;
    cout << "inorder actual:     ";
    tree.display("inorder");
    cout << "preorder expected:  20 10 30" << endl;
    cout << "preorder actual:    ";
    tree.display("preorder");
    cout << "postorder expected: 10 30 20" << endl;
    cout << "postorder actual:   ";
    tree.display("postorder");
    cout << endl;
}

void Test::runAll() {
    testEmptyTree();
    testInsertAndDuplicate();
    testLLRotation();
    testRRRotation();
    testLRRotation();
    testRLRotation();
    testHeightAndBalanceHelpers();
    testSearch();
    testTraversalHelpers();
    testRemoveMissing();
    testRemoveLeaf();
    testRemoveOneChild();
    testRemoveTwoChildren();
    testRemovalRotations();
    testRemoveRootUntilEmpty();
    testManyMixedOperations();
    testDisplayVisual();
}

void Test::summary() {
    cout << "Tests passed: " << m_passed << endl;
    cout << "Tests failed: " << m_failed << endl;
}

int main() {
    Test test;
    test.runAll();
    test.summary();
    return 0;
}