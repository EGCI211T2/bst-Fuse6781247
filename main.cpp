#include <iostream>
#include <iomanip>
using namespace std;
#include "BST.h"

int main(int argc, char **argv) {
    unsigned int i;
    BST b;
    for (i = 1; i < argc; ++i) {
        b.insert_node(atoi(argv[i]));
    }
    b.print(4); // 4 = all traversals + visual tree
}