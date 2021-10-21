/**
 * 
 * Implementation of the Queue ADT using a doubly linked list
 * 
 * Date: 20th September, 2021
 * Author: Aayush K. Patel
 * 
 */
#ifndef I_GUARD_THE_NODE_HEADER
#define I_GUARD_THE_NODE_HEADER

typedef struct songNode
{
    char *songName;
    struct songNode *next;
    struct songNode *previous;

} songNode;

songNode *newSong(char *songName);
#endif