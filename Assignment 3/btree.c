#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "btree.h"

btree *newBtree(int minimumDegree)
{
    btree *newPtr = (btree *)malloc(sizeof(btree));

    newPtr->minimumDegree = minimumDegree;

    newPtr->insertIntoBTree = insertIntoBTreeNotInStruct;
    newPtr->searchBTree = searchBTreeNotInStruct;
    newPtr->deleteFromBTree = deleteFromBTreeNotInStruct;

    return newPtr;
}

void splitNode(btree *treePtr, tree_node *parentOfNodeToSplit, int index)
{
    tree_node *nodeCreated = newTreeNode(treePtr->minimumDegree);
    tree_node *nodeToSplit = parentOfNodeToSplit->children[index];
    nodeCreated->isLeaf = nodeToSplit->isLeaf;

    int minimumDegree = treePtr->minimumDegree;

    // Transferring half the array elements to the new node
    for (int i = 0; i <= minimumDegree - 2; i++)
    {
        nodeCreated->keys[i] = nodeToSplit->keys[i + minimumDegree];
    }
    // Transferring the children pointers to the node created
    if (!nodeToSplit->isLeaf)
    {
        for (int i = 0; i <= minimumDegree - 1; i++)
        {
            nodeCreated->children[i] = nodeToSplit->children[i + minimumDegree];
        }
    }

    nodeCreated->numberOfKeys = treePtr->minimumDegree - 1;
    nodeToSplit->numberOfKeys = treePtr->minimumDegree - 1;

    // median value of nodeToSplit has to be promoted to the index of its parent
    for (int i = parentOfNodeToSplit->numberOfKeys; i >= index; i--)
    {
        if (i != parentOfNodeToSplit->numberOfKeys)
        {
            parentOfNodeToSplit->keys[i + 1] = parentOfNodeToSplit->keys[i];
        }

        if (i != index)
        {
            parentOfNodeToSplit->children[i + 1] = parentOfNodeToSplit->children[i];
        }
    }

    parentOfNodeToSplit->keys[index] = nodeToSplit->keys[minimumDegree - 1];
    parentOfNodeToSplit->children[index + 1] = nodeCreated;
    parentOfNodeToSplit->numberOfKeys++;

    diskWriteBTree(parentOfNodeToSplit);
    diskWriteBTree(nodeToSplit);
    diskWriteBTree(nodeCreated);
}

void insertIntoBTreeNotInStruct(btree *treePtr, int keyToBeInserted)
{
    tree_node *root = treePtr->root;

    if (root == NULL) // insert called first time
    {
        root = newTreeNode(treePtr->minimumDegree);
        treePtr->root = root;

        root->keys[0] = keyToBeInserted;
        root->numberOfKeys++;
        return;
    }

    if (root->numberOfKeys == 2 * treePtr->minimumDegree - 1)
    {
        tree_node *newRoot = newTreeNode(treePtr->minimumDegree);
        newRoot->isLeaf = false;
        newRoot->numberOfKeys = 0;
        newRoot->children[0] = root;

        treePtr->root = newRoot;

        splitNode(treePtr, newRoot, 0);
        insertIntoNonFullRoot(treePtr, newRoot, keyToBeInserted);
    }
    else
    {
        insertIntoNonFullRoot(treePtr, root, keyToBeInserted);
    }
}

void insertIntoNonFullRoot(btree *treePtr, tree_node *treeNodePtr, int keyToBeInserted)
{
    if (treeNodePtr->isLeaf)
    {
        int i = 0;
        for (i = 0; i < treeNodePtr->numberOfKeys; i++)
        {
            if (treeNodePtr->keys[i] > keyToBeInserted)
            {
                break;
            }
        }

        for (int j = treeNodePtr->numberOfKeys - 1; j >= i; j--)
        {
            treeNodePtr->keys[j + 1] = treeNodePtr->keys[j];
        }
        treeNodePtr->keys[i] = keyToBeInserted;
        treeNodePtr->numberOfKeys++;
        diskWriteBTree(treeNodePtr);
    }
    else
    {
        int i = 0;
        for (i = 0; i < treeNodePtr->numberOfKeys; i++)
        {
            if (treeNodePtr->keys[i] > keyToBeInserted)
            {
                break;
            }
        }

        diskReadBTree(treeNodePtr->children[i]);
        if (treeNodePtr->children[i]->numberOfKeys == 2 * treePtr->minimumDegree - 1)
        {
            splitNode(treePtr, treeNodePtr, i);
            if (keyToBeInserted > treeNodePtr->keys[i])
            {
                i++;
            }
        }

        insertIntoNonFullRoot(treePtr, treeNodePtr->children[i], keyToBeInserted);
    }
}

foundStructInfo *searchBTreeNotInStruct(tree_node *treeNodePtr, int keyToBeSearched)
{
    int i = 0;
    for (i = 0; i < treeNodePtr->numberOfKeys; i++)
    {
        if (treeNodePtr->keys[i] == keyToBeSearched)
        {
            foundStructInfo *aboutFoundElement = (foundStructInfo *)malloc(sizeof(foundStructInfo));
            aboutFoundElement->nodeFound = treeNodePtr;
            aboutFoundElement->indexInNode = i;
            return (aboutFoundElement);
        }
        if (treeNodePtr->keys[i] > keyToBeSearched)
        {
            if (treeNodePtr->isLeaf)
            {
                return (NULL);
            }
            return (searchBTreeNotInStruct(treeNodePtr->children[i], keyToBeSearched));
        }
    }

    if (treeNodePtr->isLeaf)
    {
        return (NULL);
    }
    diskReadBTree(treeNodePtr->children[i]);
    return (searchBTreeNotInStruct(treeNodePtr->children[i], keyToBeSearched));
}

// This function assumes that the key exists in the btree rooted at treeNodePtr
void deleteFromBTreeNotInStruct(btree *treePtr, tree_node *treeNodePtr, tree_node *nodeContainingKey, int indexOfKeyToBeDeleted)
{
    int keyToBeDeleted = nodeContainingKey->keys[indexOfKeyToBeDeleted];
    if (treeNodePtr->isLeaf)
    {
        printf("Case 3: Node is leaf\n");
        diskReadBTree(treeNodePtr);
        for (int i = indexOfKeyToBeDeleted; i < treeNodePtr->numberOfKeys - 1; i++)
        {
            treeNodePtr->keys[i] = treeNodePtr->keys[i + 1];
        }
        treeNodePtr->numberOfKeys--;
        diskWriteBTree(treeNodePtr);
    }
    else if (treeNodePtr == nodeContainingKey)
    {
        // key is present in an internal node
        printf("Case 2: key is present in an internal node %d\n", indexOfKeyToBeDeleted);
        if (treeNodePtr->children[indexOfKeyToBeDeleted]->numberOfKeys >= treePtr->minimumDegree)
        {
            printf("Case 2: Predecessor has enough keys\n");
            tree_node *predecessor = predecessorBTree(treeNodePtr->children[indexOfKeyToBeDeleted]);
            int predecessorIndex = predecessor->numberOfKeys - 1;
            diskReadBTree(predecessor);
            int predecessorKey = predecessor->keys[predecessorIndex];
            treePtr->deleteFromBTree(treePtr, treeNodePtr->children[indexOfKeyToBeDeleted], predecessor, predecessorIndex);
            treeNodePtr->keys[indexOfKeyToBeDeleted] = predecessorKey;
            //treeNodePtr->numberOfKeys--;
        }
        else if (treeNodePtr->children[indexOfKeyToBeDeleted + 1]->numberOfKeys >= treePtr->minimumDegree)
        {
            printf("Case 2: Successor has enough keys\n");
            tree_node *successor = successorBTree(treeNodePtr->children[indexOfKeyToBeDeleted + 1]);
            diskReadBTree(successor);
            int successorKey = successor->keys[0];
            treePtr->deleteFromBTree(treePtr, treeNodePtr->children[indexOfKeyToBeDeleted + 1], successor, 0);
            treeNodePtr->keys[indexOfKeyToBeDeleted] = successorKey;
            //treeNodePtr->numberOfKeys--;
        }
        else
        {
            mergeNodes(treePtr, treeNodePtr, indexOfKeyToBeDeleted);
            treePtr->deleteFromBTree(treePtr, treeNodePtr->children[indexOfKeyToBeDeleted], treeNodePtr->children[indexOfKeyToBeDeleted], treePtr->minimumDegree - 1);
        }
    }
    else
    {
        // key is not present in the internal node
        diskReadBTree(treeNodePtr);
        int keyToBeDeleted = nodeContainingKey->keys[indexOfKeyToBeDeleted];
        int i = 0; // Index of apt child subtree
        for (i = 0; i < treeNodePtr->numberOfKeys; i++)
        {
            if (treeNodePtr->keys[i] > keyToBeDeleted)
            {
                break;
            }
        }
        printf("Case 3, %d\n", i);
        if (treeNodePtr->children[i]->numberOfKeys >= treePtr->minimumDegree)
        {
            // The child has >= t keys
            printf("Case 3-0\n");
            treePtr->deleteFromBTree(treePtr, treeNodePtr->children[i], nodeContainingKey, indexOfKeyToBeDeleted);
        }
        else // The child has only t-1 keys
        {
            printf("Case 3-1\n");
            int flag = 0;
            // flag will be set to 1 if merging with right sibling happens
            // flag will be set to -1 if merging with left sibling happens
            // flag will stay 0 if only borrowing i.e. no merging happens

            checkInRightSibling(treePtr, treeNodePtr, i, &flag);
            printf("Flag: %d\n", flag);
            foundStructInfo *node = treePtr->searchBTree(treeNodePtr->children[i + flag], keyToBeDeleted);
            nodeContainingKey = node->nodeFound;
            indexOfKeyToBeDeleted = node->indexInNode;
            treePtr->deleteFromBTree(treePtr, treeNodePtr->children[i + flag], nodeContainingKey, indexOfKeyToBeDeleted);
        }
    }
}

tree_node *predecessorBTree(tree_node *treeNodePtr)
{
    if (treeNodePtr->isLeaf)
    {
        return (treeNodePtr);
    }

    return (predecessorBTree(treeNodePtr->children[treeNodePtr->numberOfKeys]));
}

tree_node *successorBTree(tree_node *treeNodePtr)
{
    if (treeNodePtr->isLeaf)
    {
        return (treeNodePtr);
    }

    return (successorBTree(treeNodePtr->children[0]));
}

void checkInRightSibling(btree *treePtr, tree_node *treeNodePtr, int index, int *flagPtr)
{
    if (index == treeNodePtr->numberOfKeys)
    {
        // No right sibling exists
        printf("Case 3: No right sibling\n");
        checkInLeftSibling(treePtr, treeNodePtr, index, flagPtr);
        return;
    }
    else
    {
        if (treeNodePtr->children[index + 1]->numberOfKeys >= treePtr->minimumDegree)
        {
            borrowFromRightSibling(treePtr, treeNodePtr, index);
            return;
        }
        else
        {
            checkInLeftSibling(treePtr, treeNodePtr, index, flagPtr);
            return;
        }
    }
}

void checkInLeftSibling(btree *treePtr, tree_node *treeNodePtr, int index, int *flagPtr)
{
    if (index == 0)
    {
        // No left sibling exists
        // right sibling has lesser <=t-1 keys
        // Merge with right
        mergeNodes(treePtr, treeNodePtr, index);
        *flagPtr = 1;
        return;
    }
    else
    {
        printf("Case 3: Left sibling exists\n");
        if (treeNodePtr->children[index - 1]->numberOfKeys >= treePtr->minimumDegree)
        {
            // Left sibling has >= t keys
            printf("Case 3: Left sibling has >= t keys\n");
            borrowFromLeftSibling(treePtr, treeNodePtr, index);
            return;
        }
        else
        {
            // Merge with left
            printf("Left sibling has < t nodes\n");
            mergeNodes(treePtr, treeNodePtr, index - 1);
            *flagPtr = -1;
            return;
        }
    }
}

void borrowFromRightSibling(btree *treePtr, tree_node *treeNodePtr, int index)
{
    tree_node *child = treeNodePtr->children[index];
    tree_node *rightSibling = treeNodePtr->children[index + 1];

    //Moving the key from parent to child node
    child->keys[child->numberOfKeys] = treeNodePtr->keys[index];

    //Moving the key from right sibling to parent
    treeNodePtr->keys[index] = rightSibling->keys[0];

    //Moving the child pointer from right sibling
    child->children[child->numberOfKeys + 1] = rightSibling->children[0];

    // Shifting keys to the left in rightSibling
    for (int i = 0; i <= rightSibling->numberOfKeys - 1; i++)
    {
        rightSibling->children[i] = rightSibling->children[i + 1];

        if (i != rightSibling->numberOfKeys - 1)
            rightSibling->keys[i] = rightSibling->keys[i + 1];
    }

    child->numberOfKeys++;
    rightSibling->numberOfKeys--;
}

void borrowFromLeftSibling(btree *treePtr, tree_node *treeNodePtr, int index)
{
    tree_node *child = treeNodePtr->children[index];
    tree_node *leftSibling = treeNodePtr->children[index - 1];

    // Moving the key from parent to child node
    for (int i = child->numberOfKeys; i >= 0; i--)
    {
        if (i != child->numberOfKeys)
            child->keys[i + 1] = child->keys[i];

        child->children[i + 1] = child->children[i];
    }
    child->keys[0] = treeNodePtr->keys[index - 1];

    //Moving the child pointer from left sibling
    child->children[0] = leftSibling->children[leftSibling->numberOfKeys];

    //Moving the key from left sibling to parent
    treeNodePtr->keys[index - 1] = leftSibling->keys[leftSibling->numberOfKeys - 1];

    child->numberOfKeys++;
    leftSibling->numberOfKeys--;
    traverseBTree(treePtr->root);
}

// Merging children nodes of treeNodePtr at index, index+1
void mergeNodes(btree *treePtr, tree_node *treeNodePtr, int index)
{
    tree_node *leftChild = treeNodePtr->children[index];
    tree_node *rightChild = treeNodePtr->children[index + 1];

    // Left child gets the key from parent
    leftChild->keys[treePtr->minimumDegree - 1] = treeNodePtr->keys[index];
    leftChild->numberOfKeys++;

    // Moving the keys and children pointers from right to left child
    for (int i = 0; i <= treePtr->minimumDegree - 1; i++)
    {
        if (i != treePtr->minimumDegree - 1)
        {
            leftChild->keys[treePtr->minimumDegree + i] = rightChild->keys[i];
            leftChild->numberOfKeys++;
            rightChild->numberOfKeys--;
        }
        leftChild->children[treePtr->minimumDegree + i] = rightChild->children[i];
    }

    // Shifting keys and children pointers in parent
    for (int i = index; i <= treeNodePtr->numberOfKeys - 1; i++)
    {
        if (i != treeNodePtr->numberOfKeys - 1)
        {
            treeNodePtr->keys[i] = treeNodePtr->keys[i + 1];
        }

        if (i != index)
        {
            treeNodePtr->children[i] = treeNodePtr->children[i + 1];
        }
    }
    treeNodePtr->numberOfKeys--;
    free(rightChild);
    traverseBTree(treePtr->root);
}

void traverseBTree(tree_node *treeNodePtr)
{
    if (treeNodePtr == NULL)
    {
        return;
    }

    printf("Node: ");
    for (int i = 0; i < treeNodePtr->numberOfKeys; i++)
    {
        printf("%d ", treeNodePtr->keys[i]);
    }
    printf("- %d %d", treeNodePtr->row, treeNodePtr->column);
    printf("\n");

    for (int i = 0; i <= treeNodePtr->numberOfKeys; i++)
    {
        traverseBTree(treeNodePtr->children[i]);
    }
}
