#include <stdio.h>

#include "btree.h"
#include "binary_search_tree.h"
#include "file_reader.h"
#include "disk_simulation.h"

// void deleteByKey(btree *treePtr, int key)
// {
//     foundStructInfo *node = treePtr->searchBTree(treePtr->root, key);
//     if (node == NULL)
//     {
//         printf("Not Found\n");
//     }
//     else
//     {
//         printf("Found: %d\n", node->indexInNode);
//         treePtr->deleteFromBTree(treePtr, treePtr->root, node->nodeFound, node->indexInNode);
//     }
// }

int main()
{
    char inputFile[] = "input.txt";
    char searchFile[] = "search.txt";
    char deleteFile[] = "delete.txt";

    btree *treePtr = newBtree(minDegree);

    readFileBTree(inputFile, treePtr, 1);
    int timeForInsertionInBTree = timeForBTree;

    readFileBTree(searchFile, treePtr, 0);
    int timeForSearchInBTree = timeForBTree - timeForInsertionInBTree;

    readFileBTree(deleteFile, treePtr, -1);
    int timeForDeletionInBTree = timeForBTree - timeForSearchInBTree;

    traverseBTree(treePtr->root);

    binary_search_tree *treePtr2 = newBinarySearchTree();

    readFileBST(inputFile, treePtr2, 1);
    int timeForInsertionInBST = timeForBST;

    readFileBST(searchFile, treePtr2, 0);
    int timeForSearchInBST = timeForBST - timeForInsertionInBST;

    readFileBST(deleteFile, treePtr2, -1);
    int timeForDeletionInBST = timeForBST - timeForSearchInBST;

    treePtr2->inorderTravesal(treePtr2->root);

    return 0;
}
