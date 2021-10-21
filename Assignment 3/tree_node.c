#include <stdlib.h>

#include "tree_node.h"

tree_node* newTreeNode()
{
    tree_node* newNode = (tree_node*)malloc(sizeof(tree_node));

    newNode->isLeaf = true;
    newNode->list = NULL;
    newNode->parent = NULL;
}