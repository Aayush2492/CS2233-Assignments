/**
 *
 * Implementation of a doubly linked list
 *
 * Date: 20th September, 2021
 * Author: Aayush K. Patel
 *
 */
#ifndef I_GUARD_THE_LINKED_LIST_HEADER
#define I_GUARD_THE_LINKED_LIST_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "song_node.h"

typedef struct linkedList
{
    songNode *firstSong;
    songNode *lastSong;
    unsigned numberOfSongs;

    void (*insertSong)(struct linkedList*, char *);
    bool (*searchSong)(struct linkedList*, char *);

} linkedList;

linkedList *newList();
void insertSongNotInStruct(linkedList*, char *);
bool searchSongNotInStruct(linkedList*, char *);
#endif