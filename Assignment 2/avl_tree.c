#include "avl_tree.h"
#include "binary_search_tree.h"
#include "node.h"
#include "helpful_functions.h"

avl_tree* newAVLTree()
{
    avl_tree *ptr = (avl_tree *)malloc(sizeof(avl_tree));

    ptr->root = NULL;

    // These 6 function are same for BST and AVL
    ptr->inorderTravesal = inorderTraversalNotInStruct;
    ptr->searchAVL = searchBSTNotInStruct;
    ptr->minimumAVL = minimumBSTNotInStruct;
    ptr->maximumAVL = maximumBSTNotInStruct;
    ptr->successorAVL = successorBSTNotInStruct;
    ptr->predecessorAVL = predecessorBSTNotInStruct;

    ptr->insertIntoAVL = insertIntoAVLNotInStruct;
    ptr->deleteFromAVL = deleteFromAVLNotInStruct;
    ptr->getUnbalancedNodeGrandchild = getUnbalancedNodeGrandchildNotInStruct;
    ptr->getUnbalancedNodeForDelete = getUnbalancedNodeForDeleteNotInStruct;
    ptr->rebalanceAfterDeletion = rebalanceAfterDeletionNotInStruct;

    return(ptr);
}

void insertIntoAVLNotInStruct(avl_tree* treePtr, char* songToBeAdded)
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

        do
        {
            y->height = (int)(max(getHeightOfNode(y->left), getHeightOfNode(y->right)) + 1);
            y = y->parent;
        } while(y != NULL);

        treePtr->inorderTravesal(treePtr->root);
        tree_node* unbalancedNodeGrandchild = getUnbalancedNodeGrandchildNotInStruct(newSong);

        if(unbalancedNodeGrandchild == NULL)
        {
            return;
        }
        else
        {
            tree_node* unbalancedNode = unbalancedNodeGrandchild->parent->parent;
            
            printf("Grandchild is not null\n");

            if(unbalancedNode->left != NULL)
            {
                if(unbalancedNode->left->left == unbalancedNodeGrandchild)
                {
                    printf("left left imbalance\n");
                    rightRotate(treePtr, unbalancedNode);
                }
                else if(unbalancedNode->left->right == unbalancedNodeGrandchild)
                {
                    printf("left right imbalance\n");
                    leftRotate(treePtr, unbalancedNodeGrandchild->parent);
                    rightRotate(treePtr, unbalancedNode);
                }
            }
            if(unbalancedNode->right != NULL)
            {
                if(unbalancedNode->right->right == unbalancedNodeGrandchild)
                {
                    printf("right right imbalance\n");
                    leftRotate(treePtr, unbalancedNode);
                }
                else if(unbalancedNode->right->left == unbalancedNodeGrandchild)
                {
                    printf("right left imbalance\n");
                    rightRotate(treePtr, unbalancedNodeGrandchild->parent);
                    leftRotate(treePtr, unbalancedNode);
                }
            }
        }
        printf("After rebalancing\n");
        treePtr->inorderTravesal(treePtr->root);

    }
}

tree_node* getUnbalancedNodeGrandchildNotInStruct(tree_node* nodePtr)
{
    tree_node* x = nodePtr;
    tree_node* y = x->parent;
    if(y == NULL)
    {
        return(NULL);
    }

    tree_node* z = y->parent;
    if(z == NULL)
    {
        return(NULL);
    }

    do
    {
        if(abs(getHeightOfNode(z->left) - getHeightOfNode(z->right)) > 1)
        {
            printf("Imbalance at: %s\n", z->song);
            return x;
        }
        z = z->parent;
        y = y->parent;
        x = x->parent;
    } while (z != NULL);
    
    return(NULL);
}

void leftRotate(avl_tree* treePtr, tree_node* nodePtr)
{
    tree_node* x = nodePtr;
    tree_node* y = x->right;

    y->parent = x->parent;
    if(x->parent == NULL)
    {
        treePtr->root = y;
    }
    else if(x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    x->parent = y;

    x->right = y->left;
    if(y->left != NULL)
    {
        y->left->parent = x;
    }
    y->left = x;

    do
    {
        x->height = (int)(max(getHeightOfNode(x->left), getHeightOfNode(x->right)) + 1);
        x = x->parent;
    } while(x != NULL);
    // x->height = (int)max(getHeightOfNode(x->left), getHeightOfNode(x->right)) + 1;
    // y->height = (int)max(getHeightOfNode(y->left), getHeightOfNode(y->right)) + 1;
}

void rightRotate(avl_tree* treePtr, tree_node* nodePtr)
{
    tree_node* x = nodePtr;
    tree_node* y = x->left;//

    y->parent = x->parent;
    if(x->parent == NULL)
    {
        treePtr->root = y;
    }
    else if(x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    x->parent = y;
    
    x->left = y->right;//
    if(y->right != NULL)//
    {
        y->right->parent = x;//
    }
    y->right = x;//

    do
    {
        x->height = (int)(max(getHeightOfNode(x->left), getHeightOfNode(x->right)) + 1);
        x = x->parent;
    } while(x != NULL);
     
    // x->height = (int)max(getHeightOfNode(x->left), getHeightOfNode(x->right)) + 1;
    // y->height = (int)max(getHeightOfNode(y->left), getHeightOfNode(y->right)) + 1;
}

void deleteFromAVLNotInStruct(avl_tree* treePtr, tree_node * treeNodePtr)
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
            printf("Inside the delete: Leaf case\n");
            if(treeNodePtr->parent->left == treeNodePtr)
            {
                treeNodePtr->parent->left = NULL;
            }
            else if(treeNodePtr->parent->right == treeNodePtr)
            {
                treeNodePtr->parent->right = NULL;
            }

            tree_node* parentOfDeletedNode = treeNodePtr->parent;
            tree_node* parentOfDeletedNodeTemp = treeNodePtr->parent;
            do
            {
                parentOfDeletedNode->height = (int)(max(getHeightOfNode(parentOfDeletedNode->left), getHeightOfNode(parentOfDeletedNode->right)) + 1);
                parentOfDeletedNode = parentOfDeletedNode->parent;
            } while(parentOfDeletedNode != NULL);
            printf("After height update\n");
            treePtr->inorderTravesal(treePtr->root);
            getUnbalancedNodeForDeleteNotInStruct(treePtr, parentOfDeletedNodeTemp);

        }

        free(treeNodePtr);
    }
    else if(treeNodePtr->left == NULL && treeNodePtr->right != NULL)// only right child
    {
        treeNodePtr->right->parent = treeNodePtr->parent;
        printf("Inside the delete: right case\n");
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

        tree_node* parentOfDeletedNode = treeNodePtr->parent;
        tree_node* parentOfDeletedNodeTemp = treeNodePtr->parent;
        do
        {
            parentOfDeletedNode->height = (int)(max(getHeightOfNode(parentOfDeletedNode->left), getHeightOfNode(parentOfDeletedNode->right)) + 1);
            parentOfDeletedNode = parentOfDeletedNode->parent; 
        } while(parentOfDeletedNode != NULL);
        getUnbalancedNodeForDeleteNotInStruct(treePtr, parentOfDeletedNodeTemp);

        free(treeNodePtr);
    }
    else if(treeNodePtr->left != NULL && treeNodePtr->right == NULL)// only left child
    {
        treeNodePtr->left->parent = treeNodePtr->parent;

        if(treeNodePtr->parent != NULL)
        {
            printf("Inside the delete: left case\n");
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

        tree_node* parentOfDeletedNode = treeNodePtr->parent;
        tree_node* parentOfDeletedNodeTemp = treeNodePtr->parent;
        do
        {
            parentOfDeletedNode->height = (int)(max(getHeightOfNode(parentOfDeletedNode->left), getHeightOfNode(parentOfDeletedNode->right)) + 1);
            parentOfDeletedNode = parentOfDeletedNode->parent;
        } while(parentOfDeletedNode != NULL);
        getUnbalancedNodeForDeleteNotInStruct(treePtr, parentOfDeletedNodeTemp);

        free(treeNodePtr);
    }
    else // Two children
    {
        printf("Inside the else of delete\n");
        tree_node* successorOfNodeToBeDeleted = treePtr->successorAVL(treeNodePtr);
        printf("After getting successor\n");
        swapStrings(&treeNodePtr->song, &successorOfNodeToBeDeleted->song);
        printf("After using strcpy\n");
        deleteFromAVLNotInStruct(treePtr, successorOfNodeToBeDeleted);
    }
}

void getUnbalancedNodeForDeleteNotInStruct(avl_tree* treePtr, tree_node* parentOfDeletedNode)
{
    do
    {
        printf("%s\n", parentOfDeletedNode->song);
        if(abs(getHeightOfNode(parentOfDeletedNode->left)-getHeightOfNode(parentOfDeletedNode->right)) > 1)
        {
            rebalanceAfterDeletionNotInStruct(treePtr, parentOfDeletedNode);
        }
        else
        {
            parentOfDeletedNode = parentOfDeletedNode->parent;
        }
    }while(parentOfDeletedNode != NULL);
    
}

void rebalanceAfterDeletionNotInStruct(avl_tree* treePtr, tree_node* unbalancedNode)
{
    if(getHeightOfNode(unbalancedNode->left) > getHeightOfNode(unbalancedNode->right))
    {
        if(getHeightOfNode(unbalancedNode->left->left) >= getHeightOfNode(unbalancedNode->left->right))
        {
            //left left
            printf("left left\n");
            rightRotate(treePtr, unbalancedNode);
        }
        else
        {
            printf("left right\n");
            leftRotate(treePtr, unbalancedNode->left);
            rightRotate(treePtr, unbalancedNode);
        }
    }
    else //right>=left
    {
        if(getHeightOfNode(unbalancedNode->right->right) >= getHeightOfNode(unbalancedNode->right->left))
        {
            //right right
            printf("right right\n");
            leftRotate(treePtr, unbalancedNode);
        }
        else
        {
            //right left
            printf("right left\n");
            rightRotate(treePtr, unbalancedNode->right);
            leftRotate(treePtr, unbalancedNode);
        }
    }
}
// {
//     printf("left left imbalance\n");
//     rightRotate(treePtr, unbalancedNode);
// }
// {
//     printf("left right imbalance\n");
//     leftRotate(treePtr, unbalancedNodeGrandchild->parent);
//     rightRotate(treePtr, unbalancedNode);
// }
// {
//     printf("right right imbalance\n");
//     leftRotate(treePtr, unbalancedNode);
// }
// {
//     printf("right left imbalance\n");
//     rightRotate(treePtr, unbalancedNodeGrandchild->parent);
//     leftRotate(treePtr, unbalancedNode);
// }