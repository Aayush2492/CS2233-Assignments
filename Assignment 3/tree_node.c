#include <stdlib.h>

#include "tree_node.h"

tree_node *newTreeNode(int minimumDegree)
{
    tree_node *newNode = (tree_node *)malloc(sizeof(tree_node));

    newNode->isLeaf = true;
    newNode->numberOfKeys = 0;
    newNode->keys = (int *)malloc(sizeof(int) * (2 * minimumDegree - 1));
    newNode->children = (tree_node **)malloc(sizeof(tree_node *) * (2 * minimumDegree));

    return (newNode);
}