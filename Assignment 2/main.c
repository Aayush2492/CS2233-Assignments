#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_search_tree.h"
#include "file_reader.h"

void readFile(binary_search_tree* treePtr)
{
    char *lineptr = NULL;
    size_t len;
    size_t read;
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    while((read = getdelim(&lineptr, &len, 58, fp)) != -1) 
    {
        // Remove the trailing ':' from the end
        int length = strlen(lineptr);
        if(lineptr[length-1]==':')
        {
            lineptr[length-1]='\0';
        }

        treePtr->insertIntoBST(treePtr, lineptr);
        // printf("%s\n", lineptr);
    }
}

int main()
{
    binary_search_tree* ptr = newBinarySearchTree();

    //readFile(ptr);

    //ptr->inorderTravesal(ptr->root);

    ptr->insertIntoBST(ptr, "q");
    ptr->insertIntoBST(ptr, "a");
    ptr->insertIntoBST(ptr, "d");
    ptr->insertIntoBST(ptr, "w");
    ptr->insertIntoBST(ptr, "z");
    ptr->insertIntoBST(ptr, "v");
    ptr->insertIntoBST(ptr, "c");

    ptr->inorderTravesal(ptr->root);
    
    char* searchFor = "d";
    tree_node* nodeFound = ptr->searchBST(ptr->root, searchFor);
    printf("%s\n", nodeFound->song);

    printf("Minimum: %s\n", ptr->minimumBST(ptr->root)->song);
    printf("Maximum: %s\n", ptr->maximumBST(ptr->root)->song);

    printf("Successor: %s\n",ptr->successorBST(ptr->root->left->right)->song);
    printf("Predecessor: %s\n",ptr->predecessorBST(ptr->root->right)->song);

    printf("Blah blah: %s\n", ptr->root->right->song);
    ptr->deleteFromBST(ptr, ptr->root->right);
    ptr->inorderTravesal(ptr->root);
    printf("Blah blah: %s\n", ptr->root->right->song);
    
    return 0;
}

/*include <stdio.h>
#include <stdlib.h>

#include "avl_tree.h"

int main()
{
    avl_tree* ptr = newAVLTree();

    ptr->insertIntoAVL(ptr, "q");
    ptr->inorderTravesal(ptr->root);
    ptr->insertIntoAVL(ptr, "a");
    ptr->inorderTravesal(ptr->root);
    ptr->insertIntoAVL(ptr, "d");
    ptr->inorderTravesal(ptr->root);
    ptr->insertIntoAVL(ptr, "w");
    ptr->inorderTravesal(ptr->root);
    ptr->insertIntoAVL(ptr, "z");
    ptr->inorderTravesal(ptr->root);
    ptr->insertIntoAVL(ptr, "r");
    ptr->inorderTravesal(ptr->root);
    ptr->insertIntoAVL(ptr, "s");
    ptr->inorderTravesal(ptr->root);
    ptr->insertIntoAVL(ptr, "t");

    ptr->inorderTravesal(ptr->root);
    
    // char* searchFor = "d";
    // tree_node* nodeFound = ptr->searchBST(ptr->root, searchFor);
    // printf("%s\n", nodeFound->song);

    // printf("Minimum: %s\n", ptr->minimumBST(ptr->root)->song);
    // printf("Maximum: %s\n", ptr->maximumBST(ptr->root)->song);

    // printf("Successor: %s\n",ptr->successorBST(ptr->root->left->right)->song);
    // printf("Predecessor: %s\n",ptr->predecessorBST(ptr->root->right)->song);

    // printf("Blah blah: %s\n", ptr->root->right->song);
    // ptr->deleteFromBST(ptr->root->right);
    // ptr->inorderTravesal(ptr->root);
    
    return 0;
}*/