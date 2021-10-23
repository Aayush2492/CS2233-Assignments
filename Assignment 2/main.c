#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_search_tree.h"
#include "avl_tree.h"
#include "file_reader.h"

int main()
{
    binary_search_tree* songLibrary = newBinarySearchTree();

    readFile(songLibrary);
    songLibrary->inorderTravesal(songLibrary->root);
    
    printf("Enter name of the songs you want to remove from library. End with \"-1\"\n");
    while(1)
    {
        char* str = (char*)malloc(sizeof(char)*50);
        fgets(str, sizeof(str), stdin);

        // Removing the trailing new line character from str
        int len = strlen(str);
        if(str[len-1]=='\n')
            str[len-1]='\0';
        
        if(!strcmp(str, "-1"))
        {
            printf("No more songs to be deleted from library !\n");
            break;
        }
        else
        {
            tree_node* nodeFound = songLibrary->searchBST(songLibrary->root, str);
            if(nodeFound == NULL)
            {
                printf("This song is not in library\n");
            }
            else
            {
                songLibrary->deleteFromBST(songLibrary, nodeFound);
                printf("%s has been removed from library\n", str);
            }
        }
    }

    avl_tree* songPlaylist = newAVLTree();
    printf("Enter name of the songs you want to add to playlist. End with \"-1\"\n");
    while(1)
    {
        char* str = (char*)malloc(sizeof(char)*50);
        fgets(str, sizeof(str), stdin);

        // Removing the trailing new line character from str
        int len = strlen(str);
        if(str[len-1]=='\n')
            str[len-1]='\0';
        
        if(!strcmp(str, "-1"))
        {
            printf("No more songs to add to library\n");
            break;
        }
        else
        {
            tree_node* nodeFound = songLibrary->searchBST(songLibrary->root, str);
            if(nodeFound == NULL)
            {
                printf("This song is not in library\n");
            }
            else
            {
                songPlaylist->insertIntoAVL(songPlaylist, nodeFound->song);
                printf("%s has been added to playlist\n", nodeFound->song);
            }
        }
    }

    printf("Enter name of the songs you want to remove from playlist. End with \"-1\"\n");
    while(1)
    {
        char* str = (char*)malloc(sizeof(char)*50);
        fgets(str, sizeof(str), stdin);

        // Removing the trailing new line character from str
        int len = strlen(str);
        if(str[len-1]=='\n')
            str[len-1]='\0';
        
        if(!strcmp(str, "-1"))
        {
            printf("No more songs to be deleted from playlist!\n");
            break;
        }
        else
        {
            tree_node* nodeFound = songPlaylist->searchAVL(songPlaylist->root, str);
            if(nodeFound == NULL)
            {
                printf("This song is not in library\n");
            }
            else
            {
                songPlaylist->deleteFromAVL(songPlaylist, nodeFound);
                printf("%s has been removed from playlist\n", str);
            }
        }
    }
    return 0;
}

/*void readFileTemp(avl_tree* treePtr)
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

    ptr->deleteFromAVL(ptr, ptr->root->right->right->right);
    ptr->insertIntoAVL(ptr, "x");
    ptr->deleteFromAVL(ptr, ptr->root->right->left);
    ptr->inorderTravesal(ptr->root);

    return 0;
}*/