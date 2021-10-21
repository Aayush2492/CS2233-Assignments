/*#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

int main()
{
    binary_search_tree* ptr = newBinarySearchTree();

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
    ptr->deleteFromBST(ptr->root->right);
    ptr->inorderTravesal(ptr->root);
    
    return 0;
}*/

#include <stdio.h>
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
    // ptr->insertIntoAVL(ptr, "c");

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
}