#ifndef I_GUARD_THE_BST_HEADER
#define I_GUARD_THE_BST_HEADER

#include <stdio.h>
#include <stdlib.h>

#include "bst_node.h"

typedef struct binary_search_tree
{
    bst_node *root;

    void (*insertIntoBST)(struct binary_search_tree *, int);
    void (*inorderTravesal)(bst_node *);
    bst_node *(*searchBST)(bst_node *, int);
    bst_node *(*minimumBST)(bst_node *);
    bst_node *(*maximumBST)(bst_node *);
    bst_node *(*successorBST)(bst_node *);
    bst_node *(*predecessorBST)(bst_node *);
    void (*deleteFromBST)(struct binary_search_tree *, bst_node *);

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
void insertIntoBSTNotInStruct(binary_search_tree *, int);
void inorderTraversalNotInStruct(bst_node *);
bst_node *searchBSTNotInStruct(bst_node *, int);
bst_node *minimumBSTNotInStruct(bst_node *);
bst_node *maximumBSTNotInStruct(bst_node *);
bst_node *successorBSTNotInStruct(bst_node *);
bst_node *predecessorBSTNotInStruct(bst_node *);
void deleteFromBSTNotInStruct(binary_search_tree *, bst_node *);

#endif