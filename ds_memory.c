/*
NAME:   James Moreau
STUDENT ID: 1065510
EMAIL:  jmorea03@uoguelph.ca*/

#include "ds_memory.h"

struct ds_file_struct ds_file;
struct ds_counts_struct ds_counts;

int ds_create(char *filename, long size) {
    int i;
    unsigned char s;

    ds_file.block[0].start = 0;
    ds_file.block[0].length = size;
    ds_file.block[0].alloced = 0;

    for(i=1; i < MAX_BLOCKS; ++i) { 
        ds_file.block[i].start = 0;
        ds_file.block[i].length = 0;
        ds_file.block[i].alloced = 0;
    }

    ds_file.fp = fopen(filename, "wb");
    if (ds_file.fp == NULL) { return 1;}

    if(!fwrite(&ds_file.block, sizeof(ds_file.block), 1, ds_file.fp)) {return 1;}

    for (i = 0; i<size; i++) {
        if(!fwrite(&s, sizeof(s), 1, ds_file.fp)) {return 1;}
    }

    fclose(ds_file.fp);

    return 0;
}

int ds_init(char* filename) {

    ds_file.fp = fopen(filename, "rb+");
    if (ds_file.fp == NULL) { return 1;}

    if (!fread(&ds_file.block, sizeof(struct ds_blocks_struct), MAX_BLOCKS, ds_file.fp)) { return 1;}

    ds_counts.reads = 0;
    ds_counts.writes = 0;

    return 0;
}

long ds_malloc(long amount) {
    
    int i;
    int j;

    for (i=0; i<MAX_BLOCKS; i++) {
        if ((ds_file.block[i].length >= amount) && (ds_file.block[i].alloced == 0)) {
           
            for (j = i + 1; j < MAX_BLOCKS; j++) {
                if (ds_file.block[j].length == 0) {
                    ds_file.block[j].start = ds_file.block[i].start + amount;
                    ds_file.block[j].length = ds_file.block[i].length - amount;
                    ds_file.block[j].alloced = 0;
                    break;
                }
            }

            ds_file.block[i].length = amount;
            ds_file.block[i].alloced = 1;

            return ds_file.block[i].start;
        }
    }
    return -1;
}

void ds_free(long start) {

    int i;

    for (i=0; i<MAX_BLOCKS; ++i) {
        if(ds_file.block[i].start == start) {
            ds_file.block[i].alloced = 0;
        }
    }
}

void *ds_read(void *ptr, long start, long bytes) {

    fseek(ds_file.fp, sizeof(ds_file.block) + start, SEEK_SET);

    fread(ptr, bytes, 1, ds_file.fp);

    ds_counts.reads++;

    return ptr;
}

long ds_write(long start, void *ptr, long bytes) {

    fseek(ds_file.fp, sizeof(ds_file.block) + start, SEEK_SET);

    if(!fwrite(ptr, bytes, 1, ds_file.fp)) { return 1;}
    
    ds_counts.writes++;

    return start;
}

int ds_finish() {

    fseek(ds_file.fp, 0, SEEK_SET);
    if(!fwrite(&ds_file.block, sizeof(struct ds_blocks_struct), MAX_BLOCKS, ds_file.fp)) { return 1;}
    
    fclose(ds_file.fp);
    printf("reads: %d\nwrites: %d\n", ds_counts.reads, ds_counts.writes);

    return 0;
}

void ds_test_init() {
    int i;
    printf("Block #\tStart\tLength\talloced\n");
    for ( i=0; i<MAX_BLOCKS; i++) {
        printf("%d\t%ld\t%ld\t%c\n", i, ds_file.block[i].start, ds_file.block[i].length, ds_file.block[i].alloced);
    }
}

void ds_reset() {
    printf("Reseting counts\n\n");
    ds_counts.reads = 0;
    ds_counts.writes = 0;
    
}

void ds_print_counts() {
    printf("reads: %d\nwrites: %d\n", ds_counts.reads, ds_counts.writes);
}