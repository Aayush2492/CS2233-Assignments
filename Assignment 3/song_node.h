#ifndef I_GUARD_THE_NODE_HEADER
#define I_GUARD_THE_NODE_HEADER

#include "tree_node.h"

typedef struct songNode
{
    char *songName;
    struct songNode *next;
    struct songNode *previous;
    tree_node *leftTreeNode;
    tree_node *rightTreeNode;

} songNode;

songNode *newSongNode(char *songName);
#endif