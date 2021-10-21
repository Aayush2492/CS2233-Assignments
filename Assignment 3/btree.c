#include <stdlib.h>

#include "btree.h"

btree* newBtree(unsigned minimumDegree)
{
    btree* newPtr = (btree*)malloc(sizeof(btree));

    newPtr->minimumDegree = newPtr;

    return newPtr;
}