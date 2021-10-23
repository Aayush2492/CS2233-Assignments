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

/** 
 * These functions are global functions and they will assigned to the function pointers present in the
 * struct. Externally, the function pointers defined inside the struct will be called which will be 
 * indirectly calling these global functions.
 * 
 * This is only done to give an "illusion" of OOP programming and encapsulation
 * 
 */
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