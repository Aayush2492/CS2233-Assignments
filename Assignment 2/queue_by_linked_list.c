#include "queue_by_linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node2.h"

/** 
 * These functions are global functions and they will assigned to the function pointers present in the
 * struct. Externally, the function pointers defined inside the struct will be called which will be 
 * indirectly calling these global functions.
 * 
 * This is only done to give an "illusion" of OOP programming and encapsulation
 * 
 */ 

bool isEmptyNotInStructQueue(const void *);
void enqueueNotInStruct(const void *, char *);
char *frontNotInStruct(const void *);
void dequeueNotInStruct(const void *);

queue *newQueue()
{
    queue *ptr = (queue *)malloc(sizeof(queue));

    ptr->numberOfElements = 0;

    ptr->head = NULL;
    ptr->tail = NULL;

    ptr->isEmpty = &isEmptyNotInStructQueue;
    ptr->enqueue = &enqueueNotInStruct;
    ptr->front = &frontNotInStruct;
    ptr->dequeue = &dequeueNotInStruct;

    return (ptr);
}
bool isEmptyNotInStructQueue(const void *queuePtr)
{
    return (((queue *)queuePtr)->numberOfElements == 0);
}

void enqueueNotInStruct(const void *queuePtr, char *elementToBeEnqueued)
{

    songNode *nodeptr = newSong(elementToBeEnqueued);
    if (((queue *)queuePtr)->numberOfElements == 0)
    {
        ((queue *)queuePtr)->head = nodeptr;
        ((queue *)queuePtr)->tail = nodeptr;
        ((queue *)queuePtr)->numberOfElements++;
    }
    else
    {
        ((queue *)queuePtr)->tail->next = nodeptr;
        nodeptr->previous = ((queue *)queuePtr)->tail;
        ((queue *)queuePtr)->tail = nodeptr;

        ((queue *)queuePtr)->numberOfElements++;
    }
}

char *frontNotInStruct(const void *queuePtr)
{
    if (((queue *)queuePtr)->isEmpty(queuePtr))
    {
        printf("Error: Queue is empty\n");
        return("");
    }
    else
    {
        return (((queue *)queuePtr)->head->songName);
    }
}

void dequeueNotInStruct(const void *queuePtr)
{
    if (((queue *)queuePtr)->isEmpty(queuePtr))
    {
        printf("Error: Queue is empty\n");
    }
    else
    {
        songNode *tempFrontPtr = ((queue *)queuePtr)->head;
        ((queue *)queuePtr)->head = ((queue *)queuePtr)->head->next;
        ((queue *)queuePtr)->numberOfElements--;

        //If queue contained only single element before dequeue then tail has to be assigned to NULL
        if (((queue *)queuePtr)->isEmpty(queuePtr))
        {
            ((queue *)queuePtr)->tail = NULL;
        }
        free(tempFrontPtr);
    }
}
