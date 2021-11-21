#include <stdio.h>
#include <stdlib.h>

#include "bst_node.h"

bst_node *newNode(int song)
{
    bst_node *ptr = (bst_node *)malloc(sizeof(bst_node));

    ptr->parent = NULL;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->song = song;

    return (ptr);
}