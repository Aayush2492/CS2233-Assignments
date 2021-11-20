#ifndef I_GUARD_THE_HELPFUL_FUNCTION_HEADER
#define I_GUARD_THE_HELPFUL_FUNCTION_HEADER

#include <stdbool.h>

#include "string.h"

// A separate compareString function is defined instead of using strcmp directly to provide modularity and easy
// change of compare function in case we change mind.
int min(int, int);
int max(int, int);

#endif