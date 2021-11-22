#include <stdio.h>
#include <string.h>

#include "btree.h"
#include "binary_search_tree.h"
#include "file_reader.h"
#include "disk_simulation.h"

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
    printf("After\n");

    // Resetting for
    //memset(primaryMemory, 0, 4 * t * sizeof(primaryMemory[0]));
    //memset(secondaryMemory, 0, sizeof(secondaryMemory[0][0]) * 4 * t * N);
    minDegree = 1; //minDegree = 1 for BST
    numberOfNodes = 0;

    binary_search_tree *treePtr2 = newBinarySearchTree();

    readFileBST(inputFile, treePtr2, 1);
    int timeForInsertionInBST = timeForBST;

    readFileBST(searchFile, treePtr2, 0);
    int timeForSearchInBST = timeForBST - timeForInsertionInBST;

    // readFileBST(deleteFile, treePtr2, -1);
    // int timeForDeletionInBST = timeForBST - timeForSearchInBST;

    treePtr2->inorderTravesal(treePtr2->root);

    printf("Time for Insertion In B-Tree: %d units\n", timeForInsertionInBTree);
    printf("Time for Search In B-Tree: %d units\n", timeForSearchInBTree);
    printf("Time for Deletion In B-Tree: %d units\n", timeForDeletionInBTree);
    printf("Time for Insertion In BST: %d units\n", timeForInsertionInBST);
    printf("Time for Search In BST: %d units\n", timeForSearchInBST);
    // printf("Time for Deletion In BST: %d units\n", timeForDeletionInBST);

    return 0;
}
