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
    char inputFile[] = "input.txt";
    char deleteFile[] = "delete.txt";
    char searchFile[] = "search.txt";
    btree *treePtr = newBtree(3);

    readFile(inputFile, treePtr, 1);
    printf("\n");
    //readFile(searchFile, treePtr, 0);

    // foundStructInfo *node = treePtr->searchBTree(treePtr->root, 49);
    // if (node == NULL)
    // {
    //     printf("%d not in BTree\n", 49);
    // }
    // else
    // {
    //     printf("Found: %d\n", node->indexInNode);
    // }
    // readFile(deleteFile, treePtr, -1);

    traverseBTree(treePtr->root);

    // deleteByKey(treePtr, 51);
    // deleteByKey(treePtr, 21);
    // deleteByKey(treePtr, 52);
    // deleteByKey(treePtr, 45);

    // deleteByKey(treePtr, 38);
    // deleteByKey(treePtr, 17);
    // deleteByKey(treePtr, 27);
    return 0;
}