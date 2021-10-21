#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "node.h"

void insertSongNotInStruct(const void *, char *);
bool searchSongNotInStruct(const void *, char *);

typedef struct linkedList
{
    songNode *firstSong;
    songNode *lastSong;
    unsigned numberOfSongs;

    void (*insertSong)(const void *, char *);
    bool (*searchSong)(const void *, char *);

} linkedList;

linkedList *newList()
{
    linkedList *newList = (linkedList *)malloc(sizeof(linkedList));

    newList->firstSong = NULL;
    newList->lastSong = NULL;
    newList->numberOfSongs = 0;
    newList->insertSong = insertSongNotInStruct;
    newList->searchSong = searchSongNotInStruct;

    return newList;
}

void insertSongNotInStruct(const void *songList, char *str)
{

    if (((linkedList *)(songList))->numberOfSongs == 0)
    {
        ((linkedList *)(songList))->firstSong = newSong(str);
        ((linkedList *)(songList))->lastSong = ((linkedList *)(songList))->firstSong;
        ((linkedList *)(songList))->numberOfSongs++;
    }
    else
    {
        songNode *currentSong = newSong(str);
        ((linkedList *)(songList))->lastSong->next = currentSong;
        currentSong->previous = ((linkedList *)(songList))->lastSong;
        ((linkedList *)(songList))->lastSong = currentSong;
        ((linkedList *)(songList))->numberOfSongs++;
    }
}

bool searchSongNotInStruct(const void *songList, char *str)
{
    songNode *current = ((linkedList *)(songList))->firstSong;
    for (int i = 1; i <= ((linkedList *)(songList))->numberOfSongs; i++)
    {
        if (!strcmp(current->songName, str))
        {
            return (true);
        }
        current = current->next;
    }
    return false;
}