#ifndef I_GUARD_THE_DISK_SIM_HEADER
#define I_GUARD_THE_DISK_SIM_HEADER

#include "tree_node.h"
#include "bst_node.h"

#define t 10
#define N 20
extern int timeForBTree;
extern int timeForBST;
extern int **secondaryMemory[N][2 * t];
extern int *primaryMemory[4 * t];
extern int numberOfNodes;
extern int timeForBTree;
extern int timeForBST;
extern int minDegree;
extern int currentRow;

void allocateNodeBTree(tree_node *);
void diskReadBTree(tree_node *);
void diskWriteBTree(tree_node *);

void allocateNodeBST(bst_node *);
void diskReadBST(bst_node *);
void diskWriteBST(bst_node *);
#endif