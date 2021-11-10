#include <stdlib.h>

#include "tree_node.h"

tree_node* newTreeNode()
{
    tree_node* newNode = (tree_node*)malloc(sizeof(tree_node));
    // Allocate int**, children

    newNode->isLeaf = true;
    newNode->numberOfKeys = 0;

    return(newNode);
}