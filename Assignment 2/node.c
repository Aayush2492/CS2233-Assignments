#include <stdio.h>
#include <stdlib.h>

#include "node.h"

tree_node* newNode(char* song)
{
   tree_node* ptr = (tree_node*)malloc(sizeof(tree_node));
   
    ptr->parent = NULL;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->song = song;
    ptr->height = 1;
    
    return(ptr);
}

int getHeightOfNode(tree_node* ptr)
{
    if(ptr == NULL)
    {
        return(0);
    }
    else
    {
        return(ptr->height);
    }
}