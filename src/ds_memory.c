#include "ds_memory.h"

struct ds_file_struct ds_file;
struct ds_counts_struct ds_counts;

int ds_create(char *filename, long size) {
   
    int i;

    struct ds_file_struct ds_file;
    ds_file.fp = fopen(filename, "wb+");
    if (ds_file.fp == NULL) { return -1;}

    ds_file.block[0].start = 0; /*This accessing might be wrong*/
    ds_file.block[0].length = size;
    ds_file.block[0].alloced = '0';

    for(i=1; i < MAX_BLOCKS; i++) { 
        ds_file.block[i].start = 0;
        ds_file.block[i].length = 0;
        ds_file.block[i].alloced = '0';
    }

    fclose(ds_file.fp);
    return 0;
}

int ds_init(char* filename) {

    struct ds_file_struct ds_file;
    ds_file.fp = fopen(filename, "rb+");
    if (ds_file.fp == NULL) { return -1;}

    if ( /*reading in header + error handling*/
    !(fread(ds_file.block[0].start , sizeof(long), 1, ds_file.fp) && 
    fread(ds_file.block[0].length , sizeof(long), 1, ds_file.fp) &&
    fread(ds_file.block[0].alloced , sizeof(char), 1, ds_file.fp))
    ) { return -1;}

    ds_counts.reads = 0;
    ds_counts.writes = 0;

    return 0;
}

long ds_malloc(long amount) {
    
    int i;
    int isFound = -1;
    long tempStartValue;
    long tempLengthValue;

    for (i=0; i<MAX_BLOCKS; i++) { /*Searching for free space*/
        if ((ds_file.block[i].length >= amount) && (ds_file.block[i].alloced == '0')) {
            isFound = 0;
            
            ds_file.block[i].length = amount;
            ds_file.block[i].alloced = '1';

            /*save these values*/
            tempStartValue = ds_file.block[i].start;
            tempLengthValue = ds_file.block[i].length;

        }
    }
    if (isFound == -1) {
        return -1;
    }

    for (i=0; i<MAX_BLOCKS; i++) { /*Looking for empty block*/
        if (ds_file.block[i].length == 0) {
            ds_file.block[i].start = tempStartValue + amount;
            ds_file.block[i].length = tempLengthValue - amount;
            ds_file.block[i].alloced = '0';
        }
    }

    return tempStartValue;
}