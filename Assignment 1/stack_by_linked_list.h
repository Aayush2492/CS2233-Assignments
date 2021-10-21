/**
 * 
 * Implementation of the Stack ADT using a doubly linked list
 * 
 * Date: 17th September, 2021
 * Author: Aayush K. Patel
 * 
 */

#ifndef I_GUARD_THE_STACK_BY_LL_HEADER
#define I_GUARD_THE_STACK_BY_LL_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"

//Functions which will be assigned to function pointers in the struct
void pushNotInStruct(const void *stackPtr, char *elemToBePushed);
char *topNotInStruct(const void *stackPtr);
void popNotInStruct(const void *stackPtr);
bool isEmptyNotInStruct(const void *);

typedef struct stack
{
    //Required members
    unsigned numberOfElements;
    songNode *head;
    songNode *tail;

    //Required function pointers
    void (*push)(const void *, char *);
    char *(*top)(const void *);
    void (*pop)(const void *);
    bool (*isEmpty)(const void *);

} stack;

stack *newStack();

#endif