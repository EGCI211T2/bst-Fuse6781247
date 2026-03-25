#ifndef BST_H
#define BST_H

#include <iostream>
#include <iomanip>
#include "Treenode.h"

using namespace std;

class BST {
    int size;
    TreeNodePtr rootPtr;

public:
    BST();
    ~BST();

    void insert_node(int);
    void print(int = 0);
    /* 0= inOrder 1=preOrder 2=postorder 3=printeverything 4=3+ print tree*/
};

// --- Additional Helper Functions (Non-Member Functions) ---
void inOrder(TreeNodePtr);
void preOrder(TreeNodePtr);
void postOrder(TreeNodePtr);
void printTree(TreeNodePtr, int); 
void kill(TreeNodePtr);

// --- Constructor & Destructor ---

BST::BST() {
    rootPtr = NULL;
    size = 0;
}

BST::~BST() { 
    cout << "Kill BST" << endl; 
    kill(rootPtr); // Recursive cleanup of all nodes
}

// --- BST Member Functions ---

void BST::insert_node(int value) {
    TreeNodePtr new_node = new TreeNode(value);
    if (new_node) {
        if (size == 0) {
            rootPtr = new_node;
        } else {
            TreeNodePtr t = rootPtr;
            int inserted = 0;
            while (inserted == 0) {
                // 1. Should it go left or right?
                if (value <= t->get_value()) { 
                    // 2. Move left: if available, insert; if not, move down
                    if (t->move_left() == NULL) {
                        t->set_left(new_node);
                        inserted = 1; // 3. Mark as inserted to break loop
                    } else {
                        t = t->move_left();
                    }
                } else { 
                    // Move right: if available, insert; if not, move down
                    if (t->move_right() == NULL) {
                        t->set_right(new_node);
                        inserted = 1; 
                    } else {
                        t = t->move_right();
                    }
                }
            } // end while
        }
        ++size;
cout << value << " inserted" << endl;    }
}

void BST::print(int option) {
    switch (option) {
    case 0:
        inOrder(rootPtr);
        cout << endl;
        break;
    case 1:
        preOrder(rootPtr);
        cout << endl;
        break;
    case 2:
        postOrder(rootPtr);
        cout << endl;
        break;
    case 3:
        cout << "inOrder" << endl;
        inOrder(rootPtr);
        cout << endl;
        cout << "preOrder" << endl;
        preOrder(rootPtr);
        cout << endl;
        cout << "postOrder" << endl;
        postOrder(rootPtr);
        cout << endl;
        break;
    case 4:
        // Print everything + the visual tree
        cout << "inOrder" << endl;
        inOrder(rootPtr);
        cout << endl;
        cout << "preOrder" << endl;
        preOrder(rootPtr);
        cout << endl;
        cout << "postOrder" << endl;
        postOrder(rootPtr);
        cout << endl;
        cout << "Tree" << endl;
        printTree(rootPtr, 0);
        break;
    default:
        printTree(rootPtr, 0);
        cout << endl;
    }
}

// --- Recursive Helper Implementations ---

void inOrder(TreeNodePtr treePtr) {
    if (treePtr) {
        inOrder(treePtr->move_left());            // Left
        cout << setw(3) << treePtr->get_value();  // Root
        inOrder(treePtr->move_right());           // Right
    }
}

void preOrder(TreeNodePtr treePtr) {
    if (treePtr) {
        cout << setw(3) << treePtr->get_value();  // Root
        preOrder(treePtr->move_left());           // Left
        preOrder(treePtr->move_right());          // Right
    }
}

void postOrder(TreeNodePtr treePtr) {
    if (treePtr) {
        postOrder(treePtr->move_left());          // Left
        postOrder(treePtr->move_right());         // Right
        cout << setw(3) << treePtr->get_value();  // Root
    }
}

/**
 * Visualizes the tree by rotating it 90 degrees.
 * Right children are printed at the top (with more indentation).
 */
void printTree(TreeNodePtr treePtr, int l) {
    if (treePtr) {
        printTree(treePtr->move_right(), l + 1);    // Right subtree
        cout << setw(l * 2) << "" << treePtr->get_value() << endl; // Root
        printTree(treePtr->move_left(), l + 1);     // Left subtree
    }
}

/**
 * Deletes nodes in Post-Order (Bottom-Up) to ensure 
 * children are deleted before the parent.
 */
void kill(TreeNodePtr treePtr) {
    if (treePtr) {
        kill(treePtr->move_left());
        kill(treePtr->move_right());
        delete treePtr; 
    }
}

#endif