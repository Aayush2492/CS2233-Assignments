#ifndef I_GUARD_THE_NODE_HEADER
#define I_GUARD_THE_NODE_HEADER

typedef struct tree_node
{
    struct tree_node *parent;
    struct tree_node *left;
    struct tree_node *right;
    int height;
    char *song;

} tree_node;

tree_node *newNode(char *);
int getHeightOfNode(tree_node *);

#endif