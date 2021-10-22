#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_reader.h"
#include "helpful_functions.h"

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

        char* dest = (char *)(malloc(sizeof(char) * 50));
        strcpy(dest, lineptr);

        // If we insert the keys into the same sequential order as given in the file, 
        // the generated tree will have the preorder traversal(NLR) as original file order
        treePtr->insertIntoBST(treePtr, dest);
    }
}