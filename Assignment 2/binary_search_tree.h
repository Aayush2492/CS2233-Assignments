#ifndef I_GUARD_THE_BST_HEADER
#define I_GUARD_THE_BST_HEADER

#include <stdio.h>
#include <stdlib.h>

#include "node.h"

typedef struct binary_search_tree
{
    tree_node *root;

    void (*insertIntoBST)(struct binary_search_tree *, char *);
    void (*inorderTravesal)(tree_node *);
    tree_node *(*searchBST)(tree_node *, char *);
    tree_node *(*minimumBST)(tree_node *);
    tree_node *(*maximumBST)(tree_node *);
    tree_node *(*successorBST)(tree_node *);
    tree_node *(*predecessorBST)(tree_node *);
    void (*deleteFromBST)(struct binary_search_tree* ,tree_node *);

} binary_search_tree;

/** 
 * These functions are global functions and they will assigned to the function pointers present in the
 * struct. Externally, the function pointers defined inside the struct will be called which will be 
 * indirectly calling these global functions.
 * 
 * This is only done to give an "illusion" of OOP programming and encapsulation
 * 
 */ 
binary_search_tree *newBinarySearchTree();
void insertIntoBSTNotInStruct(binary_search_tree *, char *);
void inorderTraversalNotInStruct(tree_node *);
tree_node *searchBSTNotInStruct(tree_node *, char *);
tree_node *minimumBSTNotInStruct(tree_node *);
tree_node *maximumBSTNotInStruct(tree_node *);
tree_node *successorBSTNotInStruct(tree_node *);
tree_node *predecessorBSTNotInStruct(tree_node *);
void deleteFromBSTNotInStruct(binary_search_tree*, tree_node *);

#endif