#ifndef I_GUARD_THE_TREE_NODE_HEADER
#define I_GUARD_THE_TREE_NODE_HEADER

#include <stdbool.h>

typedef struct tree_node
{
    int* keys;
    struct tree_node** children;
    unsigned numberOfKeys;
    
    bool isLeaf;

} tree_node;

tree_node *newTreeNode();
#endif