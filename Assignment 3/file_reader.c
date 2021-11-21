#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_reader.h"
#include "tree_node.h"

//mode = 1 for insertion
//mode = 0 for search
//mode = -1 for deletion
void readFile(char *fileName, btree *treePtr, int mode)
{
    char *lineptr = NULL;
    size_t len;
    size_t read;
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // 32 is the ASCII value of ' '(whitespace). getdelim will set delimeter as ' '
    while ((read = getdelim(&lineptr, &len, 32, fp)) != -1)
    {
        // Remove the trailing ' ' from the end
        int length = strlen(lineptr);
        if (lineptr[length - 1] == ' ')
        {
            lineptr[length - 1] = '\0';
        }

        char *dest = (char *)(malloc(sizeof(char) * 50));
        strcpy(dest, lineptr);
        int i = atoi(dest);
        free(dest);

        if (mode == 1)
            treePtr->insertIntoBTree(treePtr, i);
        else if (mode == 0)
        {
            foundStructInfo *node = treePtr->searchBTree(treePtr->root, i);
            if (node == NULL)
            {
                printf("%d not in BTree\n", i);
            }
            else
            {
                printf("Found: %d\n", node->indexInNode);
            }
        }
        else if (mode == -1)
        {
            foundStructInfo *node = treePtr->searchBTree(treePtr->root, i);
            if (node == NULL)
            {
                printf("%d not in BTree\n", i);
            }
            else
            {
                printf("Found: %d\n", node->indexInNode);
                treePtr->deleteFromBTree(treePtr, treePtr->root, node->nodeFound, node->indexInNode);
            }
        }
    }
}