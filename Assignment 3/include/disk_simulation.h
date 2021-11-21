#ifndef I_GUARD_THE_DISK_SIM_HEADER
#define I_GUARD_THE_DISK_SIM_HEADER

#include "tree_node.h"
#include "bst_node.h"

#define minDegree 3
extern int timeForBTree;
extern int timeForBST;

void allocateNodeBTree(tree_node *);
void diskReadBTree(tree_node *);
void diskWriteBTree(tree_node *);

void allocateNodeBST(bst_node *);
void diskReadBST(bst_node *);
void diskWriteBST(bst_node *);
#endif