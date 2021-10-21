/**
 * 
 * Implementation of the Queue ADT using a doubly linked list
 * 
 * Date: 18th September, 2021
 * Author: Aayush K. Patel
 * 
 */
#ifndef I_GUARD_THE_QUEUE_BY_LINKED_LIST_HEADER
#define I_GUARD_THE_QUEUE_BY_LINKED_LIST_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"

bool isEmptyNotInStructQueue(const void *);
void enqueueNotInStruct(const void *, char *);
char *frontNotInStruct(const void *);
void dequeueNotInStruct(const void *);

typedef struct queue
{
    unsigned numberOfElements;
    songNode *head;
    songNode *tail;

    bool (*isEmpty)(const void *);
    void (*enqueue)(const void *, char *);
    char *(*front)(const void *);
    void (*dequeue)(const void *);

} queue;

queue *newQueue();

#endif