/*guards*/
#ifndef __MEMORYH__
#define __MEMORYH__

/*Globals*/
#define MAX_BLOCKS 4096

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
int ds_create(char *, long );
int ds_init(char*);
long ds_malloc(long);
void ds_free(long);
void *ds_read(void *, long , long );
long ds_write(long, void *, long);
int ds_finish();
void ds_test_init();

#endif
