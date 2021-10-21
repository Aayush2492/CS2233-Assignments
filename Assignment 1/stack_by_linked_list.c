#include "stack_by_linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"

/** 
 * These functions are global functions and they will assigned to the function pointers present in the
 * struct. Externally, the function pointers defined inside the struct will be called which will be 
 * indirectly calling these global functions.
 * 
 * This is only done to give an "illusion" of OOP programming and encapsulation
 * 
 */ 
void pushNotInStruct(const void *stackPtr, char *elemToBePushed);
char *topNotInStruct(const void *stackPtr);
void popNotInStruct(const void *stackPtr);
bool isEmptyNotInStruct(const void *);

stack *newStack()
{
    stack *ptr = (stack *)malloc(sizeof(stack));

    ptr->numberOfElements = 0;
    ptr->head = NULL;
    ptr->tail = NULL;

    // Assigning the function pointers in struct to the externally declared global functions
    ptr->push = &pushNotInStruct;
    ptr->pop = &popNotInStruct;
    ptr->top = &topNotInStruct;
    ptr->isEmpty = &isEmptyNotInStruct;

    return ptr;
}

bool isEmptyNotInStruct(const void *stackPtr)
{
    return (((stack *)stackPtr)->numberOfElements == 0);
}

void pushNotInStruct(const void *stackPtr, char *elemToBePushed)
{
    songNode *nodeptr = newSong(elemToBePushed);
    if (((stack *)stackPtr)->numberOfElements == 0)
    {
        ((stack *)stackPtr)->head = nodeptr;
        ((stack *)stackPtr)->tail = nodeptr;
        ((stack *)stackPtr)->numberOfElements++;
    }
    else
    {
        ((stack *)stackPtr)->tail->next = nodeptr;
        nodeptr->previous = ((stack *)stackPtr)->tail;
        ((stack *)stackPtr)->tail = nodeptr;

        ((stack *)stackPtr)->numberOfElements++;
    }
}

char *topNotInStruct(const void *stackPtr)
{
    if (((stack *)stackPtr)->isEmpty(stackPtr))
    {
        printf("Error: Stack is Empty");
        return("");
    }
    else
    {
        return (((stack *)stackPtr)->tail->songName);
    }
}

void popNotInStruct(const void *stackPtr)
{
    if (((stack *)stackPtr)->isEmpty(stackPtr))
    {
        printf("Error: The Stack is Empty\n");
    }
    else
    {
        songNode *tempTopPtr = ((stack *)stackPtr)->tail;
       //If stack contained only single element before pop then tail,head has to be assigned to NULL
        if (((stack *)stackPtr)->numberOfElements==1)
        {
            ((stack *)stackPtr)->numberOfElements--;
            ((stack *)stackPtr)->tail = NULL;
            ((stack *)stackPtr)->head = NULL;
        }
        else
        {
            ((stack *)stackPtr)->tail->previous->next = NULL;
            ((stack *)stackPtr)->numberOfElements--;
            ((stack *)stackPtr)->tail = tempTopPtr->previous;
        }
        free(tempTopPtr);

    }
}