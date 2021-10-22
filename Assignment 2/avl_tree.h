#ifndef I_GUARD_THE_AVL_HEADER
#define I_GUARD_THE_AVL_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"

typedef struct avl_tree
{
    tree_node *root;

    void (*insertIntoAVL)(struct avl_tree *, char *);
    void (*inorderTravesal)(tree_node *);
    tree_node *(*searchAVL)(tree_node *, char *);
    tree_node *(*minimumAVL)(tree_node *);
    tree_node *(*maximumAVL)(tree_node *);
    tree_node *(*successorAVL)(tree_node *);
    tree_node *(*predecessorAVL)(tree_node *);
    void (*deleteFromAVL)(struct avl_tree*, tree_node *);
    tree_node *(*getUnbalancedNodeGrandchild)(tree_node *);
    void (*getUnbalancedNodeForDelete)(struct avl_tree*, tree_node *);
    void (*rebalanceAfterDeletion)(struct avl_tree*, tree_node *);

} avl_tree;

// To pass tree ptr or to pass the root node ptr in function that is the question
avl_tree *newAVLTree();
void insertIntoAVLNotInStruct(avl_tree *, char *);
void deleteFromAVLNotInStruct(avl_tree*, tree_node *);
tree_node *getUnbalancedNodeGrandchildNotInStruct(tree_node *);
void getUnbalancedNodeForDeleteNotInStruct(avl_tree*, tree_node *);
void rebalanceAfterDeletionNotInStruct(avl_tree*, tree_node *);

// Global
void leftRotate(avl_tree *, tree_node *);
void rightRotate(avl_tree *, tree_node *);

#endif