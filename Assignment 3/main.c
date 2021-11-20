#include <stdio.h>

#include "btree.h"
#include "file_reader.h"

void deleteByKey(btree *treePtr, int key)
{
    foundStructInfo *node = treePtr->searchBTree(treePtr->root, key);
    if (node == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found: %d\n", node->indexInNode);
        treePtr->deleteFromBTree(treePtr, treePtr->root, node->nodeFound, node->indexInNode);
    }
}
int main()
{
    char fileName[] = "input.txt";
    btree *treePtr = newBtree(2);

    readFile(fileName, treePtr);

    traverseBTree(treePtr->root);

    deleteByKey(treePtr, 60);
    deleteByKey(treePtr, 44);
    deleteByKey(treePtr, 32);
    deleteByKey(treePtr, 38);
    deleteByKey(treePtr, 17);
    traverseBTree(treePtr->root);

    return 0;
}