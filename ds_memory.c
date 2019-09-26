#include "ds_memory.h"

struct ds_file_struct ds_file;
struct ds_counts_struct ds_counts;

int ds_create(char *filename, long size) {
    int i;
    int temp;
    temp = 0;

    ds_file.block[0].start = 0;
    ds_file.block[0].length = size;
    ds_file.block[0].alloced = '0';

    for(i=1; i < MAX_BLOCKS; ++i) { 
        ds_file.block[i].start = 0;
        ds_file.block[i].length = 0;
        ds_file.block[i].alloced = '0';
    }

    ds_file.fp = fopen(filename, "wb+");
    if (ds_file.fp == NULL) { return 1;}


    if(!fwrite(&ds_file.block, sizeof(ds_file.block), 1, ds_file.fp)) {return 1;} /*can I write the entire block like this?*/
    
    for (i=0; i< size; i++) {
        if(!fwrite(&temp, 1, 1, ds_file.fp)) {return 1;}/*Is this the correct tway to write one byte at a time?*/
    }

    if(fclose(ds_file.fp) == EOF) {return 1;}
    return 0;
}

int ds_init(char* filename) {

    struct ds_file_struct ds_file;
    ds_file.fp = fopen(filename, "rb+");
    if (ds_file.fp == NULL) { return -1;}

    if (!(fread(ds_file.block, sizeof(struct ds_blocks_struct), MAX_BLOCKS, ds_file.fp))) { return 1;}

    ds_counts.reads = 0;
    ds_counts.writes = 0;

    return 0;
}

long ds_malloc(long amount) {
    
    int i;
    int isFound = 0;
    long tempStartValue;
    long tempLengthValue;

    for (i=0; i<MAX_BLOCKS; ++i) { /*Searching for free space*/
        if ((ds_file.block[i].length >= amount) && (ds_file.block[i].alloced == '0')) {
            isFound = 1;
            
            ds_file.block[i].length = amount;
            ds_file.block[i].alloced = '1';

            /*save these values*/
            tempStartValue = ds_file.block[i].start;
            tempLengthValue = ds_file.block[i].length;

        }
    }
    if (!isFound) { return -1;}

    for (i=0; i<MAX_BLOCKS; ++i) { /*Looking for empty block*/
        if (ds_file.block[i].length == 0) {
            ds_file.block[i].start = tempStartValue + amount;
            ds_file.block[i].length = tempLengthValue - amount;
            ds_file.block[i].alloced = '0';
        }
    }

    return tempStartValue;
}

void ds_free(long start) {

    int i;

    for (i=0; i<MAX_BLOCKS; ++i) {
        if(ds_file.block[i].start == start) {
            ds_file.block[i].alloced = '0';
        }
    }
}

void *ds_read(void *ptr, long start, long bytes) {

    fseek(ds_file.fp, sizeof(ds_file.block) + start, SEEK_SET);

    if(!fread(ptr, bytes, 1, ds_file.fp)) { return NULL;}

    ++ds_counts.reads;

    return ptr;
}

long ds_write(long start, void *ptr, long bytes) {

    fseek(ds_file.fp, sizeof(ds_file.block) + start, SEEK_SET);

    if(!fwrite(ptr, bytes, 1, ds_file.fp)) { return 1;}

    ++ds_counts.writes;

    return start;
}

int ds_finish() {

    int i;
    fseek(ds_file.fp, 0, SEEK_SET);

    for (i = 0; i<MAX_BLOCKS; i++) {
        if(!fwrite(&ds_file.block[i], sizeof(struct ds_blocks_struct), 1, ds_file.fp)) { return 0;}
    }
    fclose(ds_file.fp);

    printf("reads: %d\nwrites: %d", ds_counts.reads, ds_counts.writes);

    return 0;
}