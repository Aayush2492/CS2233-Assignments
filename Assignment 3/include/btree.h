#ifndef I_GUARD_THE_B_TREE_HEADER
#define I_GUARD_THE_B_TREE_HEADER

#include "tree_node.h"
#include "disk_simulation.h"

typedef struct btree
{
    struct tree_node *root;
    int minimumDegree;

    void (*insertIntoBTree)(struct btree *, int);
    foundStructInfo *(*searchBTree)(tree_node *, int);
    void (*deleteFromBTree)(struct btree *, tree_node *, tree_node *, int);
} btree;

btree *newBtree(int);
void insertIntoBTreeNotInStruct(btree *, int);                           //
void splitNode(btree *, tree_node *, int);                               //
void insertIntoNonFullRoot(btree *, tree_node *, int);                   //
foundStructInfo *searchBTreeNotInStruct(tree_node *, int);               //
void deleteFromBTreeNotInStruct(btree *, tree_node *, tree_node *, int); //
tree_node *predecessorBTree(tree_node *);                                //
tree_node *successorBTree(tree_node *);                                  //
void mergeNodes(btree *, tree_node *, int);
void borrowFromRightSibling(btree *, tree_node *, int);
void borrowFromLeftSibling(btree *, tree_node *, int);
void checkInRightSibling(btree *, tree_node *, int, int *); //
void checkInLeftSibling(btree *, tree_node *, int, int *);  //
void traverseBTree(tree_node *);
#endif