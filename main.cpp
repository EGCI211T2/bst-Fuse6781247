#include <iostream>
#include <iomanip>
using namespace std;
#include "BST.h"
int main(int argc, char **argv) {
  unsigned int i; // counter to loop from 1-10
  BST b;
  for (i = 1; i < argc; ++i) {
       b.insert_node (atoi(argv[i]));
  } // end for
   b.print();//in order function

  //b.searchtree(11);
 
} // end main
