/*guards*/
#ifndef __MEMORYH__
#define __MEMORYH__

/*Globals*/
MAX_BLOCKS 4096 //should this be in header file

/*Libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Structures*/
struct ds_counts_struct {
    int reads;
    int writes;
};

struct ds_blocks_struct {
    long start;
    long length;
    char alloced;
};

struct ds_file_struct {
    FILE* fp;
    struct ds_blocks_struct block[MAX_BLOCKS];

};

/*Functions*/

#endif
