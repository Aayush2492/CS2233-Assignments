/**
 *
 * Implementation of the Queue ADT using a doubly linked list
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

linkedList *newList();

#endif