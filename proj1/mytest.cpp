/**
Tiffany McCormick
CMSC341 SU 26
WC51050
Driver code for BST
The BST class doesn't expose the root or size, so tests get a Node* through search(). Since we control the insert order we always know what value the root holds, so search(rootValue) gives us the root and we can walk the tree from there with the  getters for Node.
*/

#include <iostream>
#include <string>
#include <vector>
#include "BST.h"

using namespace std;

class Test {
private:
    int m_passed;
    int m_failed;
    int m_testNum;

    // prints pass/fail for one test and updates the counters
    void report(string name, bool passed);

    // inorder walk that collects values into a vector instead of printing
    void collectInOrder(Node* node, vector<int>& out);

    // checks that vals is strictly increasing (sorted, no duplicates)
    bool isStrictlyIncreasing(const vector<int>& vals);

    //checks the inorder walk from root matches expected exactly
    bool inorderEquals(Node* root, const vector<int>& expected);

public:
    Test();

    // insert tests
    void testInsertIntoEmpty();
    void testInsertDuplicate();
    void testInsertShape();
    void testInsertDegenerateSpine();
    void testInsertInorderSorted();

    // search tests
    void testSearchEmpty();
    void testSearchNonexistent();
    void testSearchFindsAll();

    //remove tests
    void testRemoveFromEmpty();
    void testRemoveNonexistent();
    void testRemoveLeaf();
    void testRemoveOneChildRight();
    void testRemoveOneChildLeft();
    void testRemoveTwoChildren();
    void testRemoveTwoChildrenDirectSuccessor();
    void testRemoveRoot();
    void testRemoveUntilEmptyThenReuse();

    // assignment operator tests
    void testAssignmentDeepCopy();
    void testAssignmentPointerIndependence();
    void testAssignEmptyOverNonEmpty();
    void testAssignEmptyToEmpty();
    void testSelfAssignment();

    // displayNodes
    void testDisplayNodesVisual();

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

void Test::collectInOrder(Node* node, vector<int>& out) {
    if (node == nullptr) {
        return;
    }
    collectInOrder(node->getLeft(), out);
    out.push_back(node->getData());
    collectInOrder(node->getRight(), out);
}

bool Test::isStrictlyIncreasing(const vector<int>& vals) {
    for (unsigned int i = 1; i < vals.size(); i++) {
        if (vals[i] <= vals[i - 1]) {
            return false;
        }
    }
    return true;
}

bool Test::inorderEquals(Node* root, const vector<int>& expected) {
    vector<int> actual;
    collectInOrder(root, actual);
    if (actual.size() != expected.size()) {
        return false;
    }
    for (unsigned int i = 0; i < actual.size(); i++) {
        if (actual[i] != expected[i]) {
            return false;
        }
    }
    return true;
}

// edge caseinserting into an empty tree, this hits the root creation path
void Test::testInsertIntoEmpty() {
    BST tree;
    bool ok = tree.insert(10);
    Node* found = tree.search(10);
    ok = ok && (found != nullptr) && (found->getData() == 10);
    report("insert into empty tree", ok);
}

// edge case duplicates should return false and not change the tree
void Test::testInsertDuplicate() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    bool ok = (tree.insert(10) == false);   // duplicate at the root
    ok = ok && (tree.insert(5) == false);   // duplicate below the root
    vector<int> expected;
    expected.push_back(5);
    expected.push_back(10);
    ok = ok && inorderEquals(tree.search(10), expected);
    report("duplicate insert rejected, tree unchanged", ok);
}

// normal case a fixed insert order should give one exact tree shape, checked node by node through the pointers
void Test::testInsertShape() {
    BST tree;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        tree.insert(vals[i]);
    }
    // 50 went in first so search(50) is the root
    Node* root = tree.search(50);
    bool ok = (root != nullptr);
    ok = ok && root->getLeft()  && root->getLeft()->getData()  == 30;
    ok = ok && root->getRight() && root->getRight()->getData() == 70;
    ok = ok && root->getLeft()->getLeft()   && root->getLeft()->getLeft()->getData()   == 20;
    ok = ok && root->getLeft()->getRight()  && root->getLeft()->getRight()->getData()  == 40;
    ok = ok && root->getRight()->getLeft()  && root->getRight()->getLeft()->getData()  == 60;
    ok = ok && root->getRight()->getRight() && root->getRight()->getRight()->getData() == 80;
    // 20 should be a leaf
    ok = ok && root->getLeft()->getLeft()->getLeft() == nullptr;
    ok = ok && root->getLeft()->getLeft()->getRight() == nullptr;
    report("insert order gives expected tree shape", ok);
}

// edge case ascending inserts should form a right spine since a plain
void Test::testInsertDegenerateSpine() {
    BST tree;
    for (int i = 1; i <= 5; i++) {
        tree.insert(i);
    }
    Node* cur = tree.search(1); // 1 went in first so it's the root
    bool ok = true;
    for (int i = 1; i <= 5; i++) {
        ok = ok && (cur != nullptr) && (cur->getData() == i);
        ok = ok && (cur->getLeft() == nullptr); // spine nodes have no left child
        if (cur != nullptr) {
            cur = cur->getRight();
        }
    }
    ok = ok && (cur == nullptr); // spine ends after 5
    report("ascending inserts form a right spine", ok);
}

// normal case inorder traversal of a BST has to come out sorted
void Test::testInsertInorderSorted() {
    BST tree;
    int vals[] = {42, 17, 88, 3, 25, 61, 99, 10, 30, 75};
    for (int i = 0; i < 10; i++) {
        tree.insert(vals[i]);
    }
    vector<int> got;
    collectInOrder(tree.search(42), got); // 42 is the root
    bool ok = (got.size() == 10) && isStrictlyIncreasing(got);
    report("inorder is sorted after mixed inserts", ok);
}

// edge case searching an empty tree
void Test::testSearchEmpty() {
    BST tree;
    report("search on empty tree returns nullptr", tree.search(42) == nullptr);
}

// normal case searching for something that was never inserted
void Test::testSearchNonexistent() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    report("search for missing value returns nullptr", tree.search(999) == nullptr);
}

// normal case everything inserted should be findable
void Test::testSearchFindsAll() {
    BST tree;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    bool ok = true;
    for (int i = 0; i < 7; i++) {
        tree.insert(vals[i]);
    }
    for (int i = 0; i < 7; i++) {
        Node* found = tree.search(vals[i]);
        ok = ok && (found != nullptr) && (found->getData() == vals[i]);
    }
    report("search finds every inserted value", ok);
}

// edge case removing from an empty tree
void Test::testRemoveFromEmpty() {
    BST tree;
    report("remove on empty tree returns false", tree.remove(5) == false);
}

// edge case removing a value that isn't there
void Test::testRemoveNonexistent() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    bool ok = (tree.remove(999) == false);
    vector<int> expected;
    expected.push_back(30);
    expected.push_back(50);
    ok = ok && inorderEquals(tree.search(50), expected);
    report("remove of missing value returns false, tree unchanged", ok);
}

// removing leaf node
void Test::testRemoveLeaf() {
    BST tree;
    int vals[] = {50, 30, 70, 20};
    for (int i = 0; i < 4; i++) {
        tree.insert(vals[i]);
    }
    bool ok = tree.remove(20);
    ok = ok && (tree.search(20) == nullptr);
    // the parent's left pointer should be null  not dangling
    Node* root = tree.search(50);
    ok = ok && root && root->getLeft() && root->getLeft()->getLeft() == nullptr;
    vector<int> expected;
    expected.push_back(30);
    expected.push_back(50);
    expected.push_back(70);
    ok = ok && inorderEquals(root, expected);
    report("remove leaf", ok);
}

// removing node with only a right child, child takes its place
void Test::testRemoveOneChildRight() {
    BST tree;
    int vals[] = {50, 30, 70, 40}; // 30 only has a right child of 40
    for (int i = 0; i < 4; i++) {
        tree.insert(vals[i]);
    }
    bool ok = tree.remove(30);
    ok = ok && (tree.search(30) == nullptr);
    Node* root = tree.search(50);
    ok = ok && root && root->getLeft() && root->getLeft()->getData() == 40;
    report("remove node with only a right child", ok);
}

// removing node with only a left child
void Test::testRemoveOneChildLeft() {
    BST tree;
    int vals[] = {50, 30, 70, 20}; // 30 only has a left child 20
    for (int i = 0; i < 4; i++) {
        tree.insert(vals[i]);
    }
    bool ok = tree.remove(30);
    ok = ok && (tree.search(30) == nullptr);
    Node* root = tree.search(50);
    ok = ok && root && root->getLeft() && root->getLeft()->getData() == 20;
    report("remove node with only a left child", ok);
}

// removing two children, successor is deeper in the right subtree
void Test::testRemoveTwoChildren() {
    BST tree;
    int vals[] = {50, 30, 70, 60, 80, 75, 85};
    for (int i = 0; i < 7; i++) {
        tree.insert(vals[i]);
    }
    // removing 70, successor should be 75 leftmost in 70's right subtree
    bool ok = tree.remove(70);
    ok = ok && (tree.search(70) == nullptr);
    Node* root = tree.search(50);
    // 75 takes 70's spot and keeps 60 and 80 as children, and 80 loses its left child since that's where 75 was
    ok = ok && root && root->getRight() && root->getRight()->getData() == 75;
    ok = ok && root->getRight()->getLeft()  && root->getRight()->getLeft()->getData()  == 60;
    ok = ok && root->getRight()->getRight() && root->getRight()->getRight()->getData() == 80;
    ok = ok && root->getRight()->getRight()->getLeft() == nullptr;
    ok = ok && root->getRight()->getRight()->getRight() && root->getRight()->getRight()->getRight()->getData() == 85;
    report("remove node with two children, deep successor", ok);
}

// removing the successor is the node's own right child, because the right child has no left child, findMin doesn't walk anywhere
void Test::testRemoveTwoChildrenDirectSuccessor() {
    BST tree;
    int vals[] = {50, 30, 70, 80}; // 70's right child 80 has no left child
    for (int i = 0; i < 4; i++) {
        tree.insert(vals[i]);
    }
    // removing 70, successor is 80 directly
    bool ok = tree.remove(70);
    ok = ok && (tree.search(70) == nullptr);
    Node* root = tree.search(50);
    // 80 takes 70's spot with no children left over
    ok = ok && root && root->getRight() && root->getRight()->getData() == 80;
    ok = ok && root->getRight()->getLeft() == nullptr;
    ok = ok && root->getRight()->getRight() == nullptr;
    vector<int> expected;
    expected.push_back(30);
    expected.push_back(50);
    expected.push_back(80);
    ok = ok && inorderEquals(root, expected);
    report("remove node whose successor is its direct right child", ok);
}

// edge case removing the root when it has two children
void Test::testRemoveRoot() {
    BST tree;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        tree.insert(vals[i]);
    }
    bool ok = tree.remove(50);
    ok = ok && (tree.search(50) == nullptr);
    // successor of 50 is 60, so the root should hold 60 now and keep
    // its old children, and 70 loses its left child
    Node* root = tree.search(60);
    ok = ok && root && root->getLeft() && root->getLeft()->getData() == 30;
    ok = ok && root->getRight() && root->getRight()->getData() == 70;
    ok = ok && root->getRight()->getLeft() == nullptr;
    vector<int> expected;
    expected.push_back(20);
    expected.push_back(30);
    expected.push_back(40);
    expected.push_back(60);
    expected.push_back(70);
    expected.push_back(80);
    ok = ok && inorderEquals(root, expected);
    report("remove root with two children", ok);
}

// edge case empty the tree completely, then make sure it still works
void Test::testRemoveUntilEmptyThenReuse() {
    BST tree;
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    bool ok = tree.remove(1) && tree.remove(3) && tree.remove(2);
    ok = ok && (tree.search(2) == nullptr);
    ok = ok && (tree.remove(2) == false);
    // insert again after emptying
    ok = ok && tree.insert(9);
    Node* found = tree.search(9);
    ok = ok && (found != nullptr) && (found->getData() == 9);
    ok = ok && (found->getLeft() == nullptr) && (found->getRight() == nullptr);
    report("remove down to empty then reinsert", ok);
}

// normal case assignment has to deep copy, changing one tree can't affect the other (shallow copy fails this or crashes on destruct)
void Test::testAssignmentDeepCopy() {
    BST original;
    int vals[] = {50, 30, 70, 20, 40};
    for (int i = 0; i < 5; i++) {
        original.insert(vals[i]);
    }
    BST copy;
    copy.insert(999); // old contents should get replaced, not merged
    copy = original;
    bool ok = (copy.search(999) == nullptr);
    // change the copy, original shouldn't notice
    ok = ok && copy.remove(30);
    ok = ok && (copy.search(30) == nullptr);
    ok = ok && (original.search(30) != nullptr);
    // and the other way, add to the copy
    ok = ok && copy.insert(65);
    ok = ok && (original.search(65) == nullptr);
    report("operator= deep copies", ok);
}

// normal case same values but the nodes have to be different objects
void Test::testAssignmentPointerIndependence() {
    BST original;
    original.insert(50);
    original.insert(30);
    BST copy;
    copy = original;
    bool ok = (copy.search(50) != nullptr);
    ok = ok && (copy.search(50) != original.search(50));
    ok = ok && (copy.search(30) != original.search(30));
    report("operator= allocates new nodes", ok);
}

//edge case assigning an empty tree over a full one should clear it
void Test::testAssignEmptyOverNonEmpty() {
    BST empty;
    BST populated;
    populated.insert(50);
    populated.insert(30);
    populated.insert(70);
    populated = empty;
    bool ok = (populated.search(50) == nullptr);
    ok = ok && (populated.search(30) == nullptr);
    ok = ok && (populated.search(70) == nullptr);
    // should still work after being cleared
    ok = ok && populated.insert(5);
    ok = ok && (populated.search(5) != nullptr);
    report("assigning empty tree clears the target", ok);
}

//edge case empty = empty shouldn't crash or break anything
void Test::testAssignEmptyToEmpty() {
    BST a;
    BST b;
    a = b;
    bool ok = (a.search(1) == nullptr);
    ok = ok && a.insert(7);
    ok = ok && (a.search(7) != nullptr);
    report("assigning empty to empty", ok);
}

// edge case self assignment, without the guard this frees the tree and then tries to copy from the freed memory
void Test::testSelfAssignment() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    BST& alias = tree;
    tree = alias;
    vector<int> expected;
    expected.push_back(30);
    expected.push_back(50);
    expected.push_back(70);
    bool ok = inorderEquals(tree.search(50), expected);
    report("self assignment leaves tree intact", ok);
}

// displayNodes prints straight to cout so these are visual checks, expected output is printed right above the actual output
void Test::testDisplayNodesVisual() {
    BST tree;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        tree.insert(vals[i]);
    }

    cout << "expected inorder:   20 30 40 50 60 70 80" << endl;
    cout << "actual (\"InOrDeR\"): ";
    tree.displayNodes("InOrDeR"); // weird casing should still work

    cout << "expected preorder:    50 30 20 40 70 60 80" << endl;
    cout << "actual (\"PREORDER\"): ";
    tree.displayNodes("PREORDER");

    cout << "expected postorder:    20 40 30 60 80 70 50" << endl;
    cout << "actual (\"postorder\"): ";
    tree.displayNodes("postorder");

    cout << "expected: an invalid order message" << endl;
    cout << "actual:   ";
    tree.displayNodes("sideways");
}

void Test::runAll() {
    cout << "Insert tests:" << endl;
    testInsertIntoEmpty();
    testInsertDuplicate();
    testInsertShape();
    testInsertDegenerateSpine();
    testInsertInorderSorted();
    cout << endl;

    cout << "Search tests:" << endl;
    testSearchEmpty();
    testSearchNonexistent();
    testSearchFindsAll();
    cout << endl;

    cout << "Remove tests:" << endl;
    testRemoveFromEmpty();
    testRemoveNonexistent();
    testRemoveLeaf();
    testRemoveOneChildRight();
    testRemoveOneChildLeft();
    testRemoveTwoChildren();
    testRemoveTwoChildrenDirectSuccessor();
    testRemoveRoot();
    testRemoveUntilEmptyThenReuse();
    cout << endl;

    cout << "Assignment operator tests:" << endl;
    testAssignmentDeepCopy();
    testAssignmentPointerIndependence();
    testAssignEmptyOverNonEmpty();
    testAssignEmptyToEmpty();
    testSelfAssignment();
    cout << endl;

    cout << "displayNodes tests (visual):" << endl;
    testDisplayNodesVisual();
    cout << endl;

    summary();
}

void Test::summary() {
    cout << "Results:" << endl;
    cout << "passed: " << m_passed << endl;
    cout << "failed: " << m_failed << endl;
}

int main() {
    Test tester;
    tester.runAll();
    return 0;
}