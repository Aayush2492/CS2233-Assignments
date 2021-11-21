#ifndef I_GUARD_THE_FILE_READER_HEADER
#define I_GUARD_THE_FILE_READER_HEADER

#include "btree.h"
#include "binary_search_tree.h"

void readFileBTree(char *, btree *, int);
void readFileBST(char *, binary_search_tree *, int);

#endif