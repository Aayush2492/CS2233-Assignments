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
    ptr->height = 1;

    return (ptr);
}

int getHeightOfNode(bst_node *ptr)
{
    if (ptr == NULL)
    {
        return (0);
    }
    else
    {
        return (ptr->height);
    }
}