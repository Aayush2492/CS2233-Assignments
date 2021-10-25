#include <stdlib.h>

#include "tree_node.h"

tree_node* newTreeNode()
{
    tree_node* newNode = (tree_node*)malloc(sizeof(tree_node));
    // Allocate char**, children

    newNode->isLeaf = true;
    newNode->parent = NULL;
    newNode->numberOfKeys = 0;
}