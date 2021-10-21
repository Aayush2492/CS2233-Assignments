#include "node.h"
#include <stdio.h>
#include <stdlib.h>

songNode *newSong(char *songName)
{
    songNode *newNode = (songNode *)malloc(sizeof(songNode));
    newNode->next = NULL;
    newNode->previous = NULL;
    newNode->songName = songName;
    return newNode;
}