#ifndef I_GUARD_THE_NODE_HEADER
#define I_GUARD_THE_NODE_HEADER

typedef struct bst_node
{
    struct bst_node *parent;
    struct bst_node *left;
    struct bst_node *right;
    int song;
    int row, column;

} bst_node;

bst_node *newNode(int);

#endif