#include "song_node.h"
#include <stdlib.h>

songNode *newSongNode(char *songName)
{
    songNode *newNode = (songNode *)malloc(sizeof(songNode));

    newNode->next = NULL;
    newNode->previous = NULL;
    newNode->songName = songName;
    newNode->leftTreeNode = NULL;
    newNode->rightTreeNode = NULL;

    return newNode;
}