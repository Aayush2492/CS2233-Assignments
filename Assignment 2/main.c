#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_search_tree.h"
#include "avl_tree.h"
#include "file_reader.h"

/*
int main()
{
    binary_search_tree* ptr = newBinarySearchTree();

    readFile(ptr);
    ptr->inorderTravesal(ptr->root);
    
    char* searchFor = "d";
    tree_node* nodeFound = ptr->searchBST(ptr->root, searchFor);
    printf("%s\n", nodeFound->song);

    printf("Minimum: %s\n", ptr->minimumBST(ptr->root)->song);
    printf("Maximum: %s\n", ptr->maximumBST(ptr->root)->song);

    printf("Successor: %s\n",ptr->successorBST(ptr->root->left->right)->song);
    printf("Predecessor: %s\n",ptr->predecessorBST(ptr->root->right)->song);

    printf("Blah blah: %s\n", ptr->root->right->song);
    ptr->deleteFromBST(ptr, ptr->root);
    ptr->inorderTravesal(ptr->root);
    printf("Blah blah: %s\n", ptr->root->song);
    
    return 0;
}
*/

void readFileTemp(avl_tree* treePtr)
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

        char* dest = (char *)(malloc(sizeof(char) * 50));
        strcpy(dest, lineptr);

        // If we insert the keys into the same sequential order as given in the file, 
        // the generated tree will have the preorder traversal(NLR) as original file order
        treePtr->insertIntoAVL(treePtr, dest);
    }
}

int main()
{
    avl_tree* ptr = newAVLTree();
    readFileTemp(ptr);

    ptr->inorderTravesal(ptr->root);
    return 0;
}