#include <stdlib.h>
#include <stdbool.h>

#include "btree.h"

btree* newBtree(unsigned minimumDegree)
{
    btree* newPtr = (btree*)malloc(sizeof(btree));

    newPtr->minimumDegree = minimumDegree;

    newPtr->insertIntoBTree = insertIntoBTreeNotInStruct;

    return newPtr;
}

void splitNode(btree* treePtr, tree_node* parentOfNodeToSplit, unsigned index)
{
    tree_node* nodeCreated = newTreeNode();
    tree_node* nodeToSplit = parentOfNodeToSplit->children[index];
    nodeCreated->isLeaf = nodeToSplit->isLeaf;
    
    unsigned minimumDegree = treePtr->minimumDegree;

    // Transferring half the array elements to the new node
    for(int i = 0; i<=minimumDegree-2; i++)
    {
        nodeCreated->keys[i] = nodeToSplit->keys[i+minimumDegree];
    }
    
    // Transferring the children pointers to the node created
    if(!nodeToSplit->isLeaf)
    {
        for(int i=0; i<=minimumDegree-1; i++)
        {
            nodeCreated->children[i] = nodeToSplit->children[i + minimumDegree];
        }
    }

    nodeCreated->numberOfKeys = treePtr->minimumDegree-1;
    nodeToSplit->numberOfKeys = treePtr->minimumDegree-1;

    // median value of nodeToSplit has to be promoted to the index of its parent

    for(int i = parentOfNodeToSplit->numberOfKeys; i>= index; i--)
    {
        if(i != parentOfNodeToSplit->numberOfKeys)
        {
            parentOfNodeToSplit->keys[i+1] = parentOfNodeToSplit->keys[i];
        }
        
        if(i != index)
        {
            parentOfNodeToSplit->children[i+1] = parentOfNodeToSplit->children[i];
        }
    }
    parentOfNodeToSplit->keys[index] = nodeToSplit->keys[minimumDegree-1];
    parentOfNodeToSplit->children[index+1] = nodeCreated;
    parentOfNodeToSplit->numberOfKeys++;
}

void insertIntoBTreeNotInStruct(btree* treePtr, int keyToBeInserted)
{
    tree_node* root = treePtr->root;
    if(root->numberOfKeys == 2*treePtr->minimumDegree -1)
    {
        tree_node* newRoot = newTreeNode();
        newRoot->isLeaf = false;
        newRoot->numberOfKeys = 0;
        newRoot->children[0] = root;

        treePtr->root = newRoot;

        splitNode(treePtr, newRoot, 0);
    }
    else
    {

    }
}

void insertIntoNonFullRoot(btree* treePtr, tree_node* treeNodePtr, int keyToBeInserted)
{
    if(treeNodePtr->isLeaf)
    {
        int i=0;
        for(i=0; i<treeNodePtr->numberOfKeys; i++)
        {
            if(treeNodePtr->keys[i] > keyToBeInserted)
            {
                break;
            }
        }

        for(int j = i; j<treeNodePtr->numberOfKeys-1; j++)
        {
            treeNodePtr->keys[j+1] = treeNodePtr->keys[j];
        }
        treeNodePtr->keys[i] = keyToBeInserted;
        treeNodePtr->numberOfKeys++;

    }
    else
    {
        int i=0;
        for(i=0;i<treeNodePtr->numberOfKeys; i++)
        {
            if(treeNodePtr->keys[i] > keyToBeInserted)
            {
                break;
            }
        }

        if(treeNodePtr->children[i]->numberOfKeys == 2*treePtr->minimumDegree-1)
        {
            splitNode(treePtr, treeNodePtr, i);
        }

        if(keyToBeInserted > treeNodePtr->keys[i])
        {
            i++;
        }

        insertIntoNonFullRoot(treePtr, treeNodePtr->children[i], keyToBeInserted);
        
    }
}

