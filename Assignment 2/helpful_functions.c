#include <stdbool.h>

#include "helpful_functions.h"

bool compareStrings(char *a, char *b)
{
    return (strcmp(a, b)>0);
}

int min(int a, int b)
{
    return((a<b)?a:b);
}

int max(int a, int b)
{
    return((a>b)?a:b);
}