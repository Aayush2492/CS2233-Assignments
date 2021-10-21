#include <stdio.h>
#include <stdlib.h>

#include "file_reader.h"

void readFile(binary_search_tree* treePtr)
{
    FILE* fp = fopen("input.txt", "r");
    char *lineptr = NULL;
    size_t len;
    size_t read;
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    while((read = getdelim(&lineptr, &len, 58, fp)) != -1) 
    {
        int length = strlen(lineptr);

        if(lineptr[length-1]==':')
        {
            lineptr[length-1]='\0';
        }
    
        printf("%s\n", lineptr);
    }
}