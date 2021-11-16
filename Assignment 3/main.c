#include <stdio.h>

#include "btree.h"
#include "file_reader.h"

void traverseBTree(tree_node* treeNodePtr)
{
    if(treeNodePtr == NULL)
    {
        return;
    }

    printf("Node: ");
    for(int i=0; i<treeNodePtr->numberOfKeys; i++)
    {
        printf("%d ", treeNodePtr->keys[i]);
    }
    printf("\n");

    for(int i=0; i<= treeNodePtr->numberOfKeys; i++)
    {
        traverseBTree(treeNodePtr->children[i]);
    }

}
int main()
{
    btree* treePtr = newBtree(3);

    readFile(treePtr, 1);

    traverseBTree(treePtr->root);

    readFile(treePtr, 0);

    return 0;
}