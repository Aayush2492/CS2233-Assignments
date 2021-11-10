#ifndef I_GUARD_THE_B_TREE_HEADER
#define I_GUARD_THE_B_TREE_HEADER

#include "tree_node.h"

typedef struct btree
{
    struct tree_node *root;
    unsigned minimumDegree;

    void (*insertIntoBTree)(btree*, int);
} btree;

btree *newBtree(unsigned);
void insertIntoBTreeNotInStruct(btree*, int);
void splitNode(btree*, tree_node*, unsigned);
void insertIntoNonFullRoot(btree*, tree_node*, int);

#endif