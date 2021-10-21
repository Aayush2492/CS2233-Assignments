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
    void (*deleteFromBST)(tree_node *);

} binary_search_tree;

// To pass tree ptr or to pass the root node ptr in function that is the question
binary_search_tree *newBinarySearchTree();
void insertIntoBSTNotInStruct(binary_search_tree *, char *);
void inorderTraversalNotInStruct(tree_node *);
tree_node *searchBSTNotInStruct(tree_node *, char *);
tree_node *minimumBSTNotInStruct(tree_node *);
tree_node *maximumBSTNotInStruct(tree_node *);
tree_node *successorBSTNotInStruct(tree_node *);
tree_node *predecessorBSTNotInStruct(tree_node *);
void deleteFromBSTNotInStruct(tree_node *);

#endif