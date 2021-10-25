#ifndef I_GUARD_THE_B_TREE_HEADER
#define I_GUARD_THE_B_TREE_HEADER

typedef struct btree
{
    struct btree *root;
    unsigned minimumDegree;
} btree;

btree *newBtree(unsigned);
#endif