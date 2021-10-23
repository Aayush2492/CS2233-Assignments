#include <string.h>
#include <stdio.h>

#include "binary_search_tree.h"
#include "helpful_functions.h"

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

void insertIntoBSTNotInStruct(binary_search_tree* treePtr, char* songToBeAdded)
{
    if(treePtr->root == NULL) // Empty tree case
    {
        treePtr->root = newNode(songToBeAdded);
    }
    else
    {
        tree_node* y = NULL;
        tree_node* x = treePtr->root;
        while(x != NULL)
        {
            y = x;
            if(compareStrings(x->song, songToBeAdded) > 0)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        tree_node* newSong = newNode(songToBeAdded);
        newSong->parent = y;
        
        if(compareStrings(y->song, songToBeAdded))
        {
            y->left = newSong;
            printf("Inserted on left: %s\n",y->left->song);          
        }
        else
        {
            y->right = newSong;
            printf("Inserted on right: %s\n",y->right->song);
        }

    }
}

void inorderTraversalNotInStruct(tree_node* treeNodePtr)
{
    if(treeNodePtr == NULL)
    {
        return;
    }

    inorderTraversalNotInStruct(treeNodePtr->left);
    printf("%s: %d\n",treeNodePtr->song, getHeightOfNode(treeNodePtr));
    inorderTraversalNotInStruct(treeNodePtr->right);
}

tree_node* searchBSTNotInStruct(tree_node* treeNodePtr, char* songToBeSearched)
{
    tree_node* x = treeNodePtr;
    printf("%s:%s\n", x->song, songToBeSearched);
    if(x == NULL)
    {
        return(NULL);
    }
    else if(strcmp(x->song, songToBeSearched)==0)
    {
        printf("Here: %s\ns", x->song);
        return(x);
    }
    else
    { 
        if(compareStrings(x->song, songToBeSearched) > 0)
        {
            searchBSTNotInStruct(treeNodePtr->left,songToBeSearched);
        }
        else
        {
            searchBSTNotInStruct(treeNodePtr->right, songToBeSearched);
        }
    }
}

tree_node* minimumBSTNotInStruct(tree_node* treeNodePtr)
{
    while(treeNodePtr->left != NULL)
    {
        treeNodePtr = treeNodePtr->left;
    }
    return(treeNodePtr);
}

tree_node* maximumBSTNotInStruct(tree_node* treeNodePtr)
{
    while(treeNodePtr->right != NULL)
    {
        treeNodePtr = treeNodePtr->right;
    }
    return(treeNodePtr);
}

tree_node* successorBSTNotInStruct(tree_node* treeNodePtr)
{
    if(treeNodePtr->right != NULL)
    {
        return(minimumBSTNotInStruct(treeNodePtr->right));
    }
    else
    {
        tree_node* y = treeNodePtr->parent;
        while(y != NULL && treeNodePtr == y->right)
        {
            treeNodePtr = y;
            y = y->parent;
        }
        return y;
    }
}

tree_node* predecessorBSTNotInStruct(tree_node* treeNodePtr)
{
    if(treeNodePtr->left != NULL)
    {
        return(maximumBSTNotInStruct(treeNodePtr->left));
    }
    else
    {
        tree_node* y = treeNodePtr->parent;
        while(y != NULL && treeNodePtr == y->left)
        {
            treeNodePtr = y;
            y = y->parent;
        }
        return y;
    }
}

void deleteFromBSTNotInStruct(binary_search_tree* treePtr,tree_node* treeNodePtr)
{
    printf("Inside the delete\n");
    if(treeNodePtr->left == NULL && treeNodePtr->right == NULL)// Leaf node
    {
        if(treeNodePtr->parent == NULL)// This is the only node
        {
            treePtr->root = NULL;
        }
        else
        {
            if(treeNodePtr->parent->left == treeNodePtr)
            {
                treeNodePtr->parent->left = NULL;
            }
            else if(treeNodePtr->parent->right == treeNodePtr)
            {
                treeNodePtr->parent->right = NULL;
            }
        }
        free(treeNodePtr);
    }
    else if(treeNodePtr->left == NULL && treeNodePtr->right != NULL)// only right subtree
    {
        treeNodePtr->right->parent = treeNodePtr->parent;

        if(treeNodePtr->parent != NULL)
        {
            if(treeNodePtr->parent->left == treeNodePtr)
            {
                treeNodePtr->parent->left = treeNodePtr->right;
            }
            else if(treeNodePtr->parent->right == treeNodePtr)
            {
                treeNodePtr->parent->right = treeNodePtr->right;
            }
        }
        else
        {
            treePtr->root = treeNodePtr->right;
        }
        free(treeNodePtr);
    }
    else if(treeNodePtr->left != NULL && treeNodePtr->right == NULL)// only left subtree
    {
        treeNodePtr->left->parent = treeNodePtr->parent;

        if(treeNodePtr->parent != NULL)
        {
            if(treeNodePtr->parent->left == treeNodePtr)
            {
                treeNodePtr->parent->left = treeNodePtr->left;
            }
            else if(treeNodePtr->parent->right == treeNodePtr)
            {
                treeNodePtr->parent->right = treeNodePtr->left;
            }
        }
        else
        {
            treePtr->root = treeNodePtr->left;
        }

        free(treeNodePtr);
    }
    else // Two children
    {
        printf("Inside the else of delete\n");
        tree_node* successorOfNodeToBeDeleted = successorBSTNotInStruct(treeNodePtr);
        printf("After getting successor\n");
        swapStrings(&treeNodePtr->song, &successorOfNodeToBeDeleted->song);
        printf("After using strcpy\n");
        deleteFromBSTNotInStruct(treePtr, successorOfNodeToBeDeleted);
    }
}