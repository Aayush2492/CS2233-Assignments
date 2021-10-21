#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "linked_list.h"

linkedList *newList()
{
    linkedList *newList = malloc(sizeof(linkedList));

    newList->firstSong = NULL;
    newList->lastSong = NULL;
    newList->numberOfSongs = 0;
    
    newList->insertSong = insertSongNotInStruct;
    newList->searchSong = searchSongNotInStruct;

    return newList;
}

void insertSongNotInStruct(linkedList *songList, char *str)
{

    if (songList->numberOfSongs == 0)
    {
        songList->firstSong = newSong(str);
        songList->lastSong = songList->firstSong;
        songList->numberOfSongs++;
    }
    else
    {
        songNode *currentSong = newSongNode(str);
        songList->lastSong->next = currentSong;
        currentSong->previous = songList->lastSong;
        songList->lastSong = currentSong;
        songList->numberOfSongs++;
    }
}

bool searchSongNotInStruct(linkedList *songList, char *str)
{
    songNode *current = songList->firstSong;
    for (int i = 1; i <= songList->numberOfSongs; i++)
    {
        if (!strcmp(current->songName, str))
        {
            return (true);
        }
        current = current->next;
    }
    return false;
}