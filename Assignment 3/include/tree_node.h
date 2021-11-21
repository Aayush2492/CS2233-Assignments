#ifndef I_GUARD_THE_TREE_NODE_HEADER
#define I_GUARD_THE_TREE_NODE_HEADER

#include <stdbool.h>

typedef struct tree_node
{
    int *keys;
    struct tree_node **children;
    int numberOfKeys;
    bool isLeaf;
    int row, column; // Coordinates in secondary memory

} tree_node;

typedef struct foundStructInfo
{
    tree_node *nodeFound;
    int indexInNode;
} foundStructInfo;

tree_node *newTreeNode(int);
#endif