#include <stdio.h>

#include "binary_search_tree.h"
#include "helpful_functions.h"
#include "disk_simulation.h"

binary_search_tree *newBinarySearchTree()
{
    binary_search_tree *ptr = (binary_search_tree *)malloc(sizeof(binary_search_tree));

    ptr->root = NULL;

    ptr->insertIntoBST = insertIntoBSTNotInStruct;
    ptr->inorderTravesal = inorderTraversalNotInStruct;
    ptr->searchBST = searchBSTNotInStruct;
    ptr->minimumBST = minimumBSTNotInStruct;
    ptr->maximumBST = maximumBSTNotInStruct;
    ptr->successorBST = successorBSTNotInStruct;
    ptr->predecessorBST = predecessorBSTNotInStruct;
    ptr->deleteFromBST = deleteFromBSTNotInStruct;

    return (ptr);
}

void insertIntoBSTNotInStruct(binary_search_tree *treePtr, int songToBeAdded)
{
    if (treePtr->root == NULL) // Empty tree case
    {
        treePtr->root = newNode(songToBeAdded);
    }
    else // y will be the parent of x and they will simultaneously go down the tree until x becomes NULL.
         // y should be the new node
    {
        bst_node *y = NULL;
        bst_node *x = treePtr->root;
        while (x != NULL)
        {
            if (x->row != currentRow)
            {
                diskReadBST(x);
            }
            else
            {
                timeForBST += 1;
            }

            y = x;
            if (x->song > songToBeAdded)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        bst_node *newSong = newNode(songToBeAdded);
        newSong->parent = y;

        if (y->song > songToBeAdded)
        {
            y->left = newSong;
        }
        else
        {
            y->right = newSong;
        }
    }
}

void inorderTraversalNotInStruct(bst_node *treeNodePtr)
{
    if (treeNodePtr == NULL)
    {
        return;
    }

    inorderTraversalNotInStruct(treeNodePtr->left);
    printf("%d: (%d,%d)\n", treeNodePtr->song, treeNodePtr->row, treeNodePtr->column);
    inorderTraversalNotInStruct(treeNodePtr->right);
}

bst_node *searchBSTNotInStruct(bst_node *treeNodePtr, int songToBeSearched)
{
    bst_node *x = treeNodePtr;

    if (x != NULL)
    {
        if (x->row != currentRow)
        {
            diskReadBST(x);
        }
        else
        {
            timeForBST += 1;
        }
    }

    if (x == NULL) // Not found case
    {
        return (NULL);
    }
    else if (x->song == songToBeSearched) // Song found
    {
        return (x);
    }
    else
    {
        if (x->song > songToBeSearched)
        {
            searchBSTNotInStruct(treeNodePtr->left, songToBeSearched);
        }
        else
        {
            searchBSTNotInStruct(treeNodePtr->right, songToBeSearched);
        }
    }
}

bst_node *minimumBSTNotInStruct(bst_node *treeNodePtr)
{
    while (treeNodePtr->left != NULL)
    {
        treeNodePtr = treeNodePtr->left;
    }
    return (treeNodePtr);
}

bst_node *maximumBSTNotInStruct(bst_node *treeNodePtr)
{
    while (treeNodePtr->right != NULL)
    {
        treeNodePtr = treeNodePtr->right;
    }
    return (treeNodePtr);
}

bst_node *successorBSTNotInStruct(bst_node *treeNodePtr)
{
    if (treeNodePtr->right != NULL)
    {
        return (minimumBSTNotInStruct(treeNodePtr->right));
    }
    else
    {
        bst_node *y = treeNodePtr->parent;
        while (y != NULL && treeNodePtr == y->right)
        {
            treeNodePtr = y;
            y = y->parent;
        }
        return y;
    }
}

bst_node *predecessorBSTNotInStruct(bst_node *treeNodePtr)
{
    if (treeNodePtr->left != NULL)
    {
        return (maximumBSTNotInStruct(treeNodePtr->left));
    }
    else
    {
        bst_node *y = treeNodePtr->parent;
        // we will find the first ancestor of given node such that the given node is present in the left
        // subtree of that node, which will be the ancestor of required node
        while (y != NULL && treeNodePtr == y->left)
        {
            treeNodePtr = y;
            y = y->parent;
        }
        return y;
    }
}

void deleteFromBSTNotInStruct(binary_search_tree *treePtr, bst_node *treeNodePtr)
{
    if (treeNodePtr->left == NULL && treeNodePtr->right == NULL) // Leaf node
    {
        if (treeNodePtr->parent == NULL) // This is the only node
        {
            treePtr->root = NULL;
        }
        else
        {
            if (treeNodePtr->parent->left == treeNodePtr)
            {
                treeNodePtr->parent->left = NULL;
            }
            else if (treeNodePtr->parent->right == treeNodePtr)
            {
                treeNodePtr->parent->right = NULL;
            }
        }
        free(treeNodePtr);
    }
    else if (treeNodePtr->left == NULL && treeNodePtr->right != NULL) // only right subtree of node to be deleted
    {
        treeNodePtr->right->parent = treeNodePtr->parent;

        if (treeNodePtr->parent != NULL)
        {
            if (treeNodePtr->parent->left == treeNodePtr)
            {
                treeNodePtr->parent->left = treeNodePtr->right;
            }
            else if (treeNodePtr->parent->right == treeNodePtr)
            {
                treeNodePtr->parent->right = treeNodePtr->right;
            }
        }
        else // This is root node itself
        {
            treePtr->root = treeNodePtr->right;
        }
        free(treeNodePtr);
    }
    else if (treeNodePtr->left != NULL && treeNodePtr->right == NULL) // only left subtree of node to be deleted
    {
        treeNodePtr->left->parent = treeNodePtr->parent;

        if (treeNodePtr->parent != NULL)
        {
            if (treeNodePtr->parent->left == treeNodePtr)
            {
                treeNodePtr->parent->left = treeNodePtr->left;
            }
            else if (treeNodePtr->parent->right == treeNodePtr)
            {
                treeNodePtr->parent->right = treeNodePtr->left;
            }
        }
        else // This is root node itself
        {
            treePtr->root = treeNodePtr->left;
        }

        free(treeNodePtr);
    }
    else // Two children of node to be deleted
    {
        bst_node *successorOfNodeToBeDeleted = successorBSTNotInStruct(treeNodePtr);

        if (treeNodePtr->row != currentRow)
        {
            diskReadBST(treeNodePtr);
        }
        else
        {
            timeForBST += 1;
        }

        int temp = treeNodePtr->song;

        if (successorOfNodeToBeDeleted->row != currentRow)
        {
            diskReadBST(successorOfNodeToBeDeleted);
        }
        else
        {
            timeForBST += 1;
        }

        treeNodePtr->song = successorOfNodeToBeDeleted->song;
        diskWriteBST(treeNodePtr);

        successorOfNodeToBeDeleted->song = temp;
        diskWriteBST(treeNodePtr);

        deleteFromBSTNotInStruct(treePtr, successorOfNodeToBeDeleted);
    }
}