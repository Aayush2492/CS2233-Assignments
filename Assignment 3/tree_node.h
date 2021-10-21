#ifndef I_GUARD_THE_TREE_NODE_HEADER
#define I_GUARD_THE_TREE_NODE_HEADER

#include <stdbool.h>

#include "linked_list.h"

typedef struct tree_node
{
    struct tree_node *parent;
    linkedList *list;
    bool isLeaf;
} tree_node;

tree_node *newTreeNode();
#endif