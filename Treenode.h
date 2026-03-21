#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

class TreeNode {
    TreeNode *leftPtr;
    int data;
    TreeNode *rightPtr;
public:
    TreeNode(int);
    ~TreeNode();
    void set_left(TreeNode* t);
    void set_right(TreeNode* t) { rightPtr = t; }
    int get_value() { return data; }
    TreeNode* move_right() { return rightPtr; }
    TreeNode* move_left()  { return leftPtr;  }
};

typedef TreeNode* TreeNodePtr;

void TreeNode::set_left(TreeNode *t) {
    leftPtr = t;
}

TreeNode::TreeNode(int x) {
    data = x;
    leftPtr  = NULL;
    rightPtr = NULL;
}

TreeNode::~TreeNode() {
    cout << "Deleting " << data << endl;
}

#endif