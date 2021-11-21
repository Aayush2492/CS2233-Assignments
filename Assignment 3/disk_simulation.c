#include <math.h>
#include <stdio.h>

#include "disk_simulation.h"

#define t 10
#define N 20
#define minDegree 3
int **secondaryMemory[N][2 * t] = {0};
int *primaryMemory[4 * t] = {0};
int numberOfBTreeNodes = 0;
int time = 0;

void allocateNodeBTree(tree_node *treeNodePtr)
{
    // Assign coordinate to node base on existing number of nodes in sec memory
    int maxBTreeNodesInABlock = (int)floor(((double)(2 * t)) / (2 * minDegree - 1));

    int row, column;
    row = numberOfBTreeNodes / maxBTreeNodesInABlock;
    column = (numberOfBTreeNodes % maxBTreeNodesInABlock) * (2 * minDegree - 1);

    numberOfBTreeNodes++;
    printf(":%d:\n", numberOfBTreeNodes);
    treeNodePtr->row = row;
    treeNodePtr->column = column;

    time += 1;
}

void diskReadBTree(tree_node *treeNodePtr)
{
    // Add the node values to primary memory
    for (int i = 0; i < 2 * t; i++)
    {
        primaryMemory[i] = secondaryMemory[treeNodePtr->row][i];
    }
    time += 10;
}

void diskWriteBTree(tree_node *treeNodePtr)
{
    // Make changes in secondary memory
    for (int i = 0; i < 2 * t; i++)
    {
        secondaryMemory[treeNodePtr->row][i] = primaryMemory[i];
    }
    time += 10;
}

void allocateNodeBST(bst_node *treeNodePtr)
{
}

void diskReadBST(bst_node *treeNodePtr)
{
}

void diskWriteBST(bst_node *treeNodePtr)
{
}