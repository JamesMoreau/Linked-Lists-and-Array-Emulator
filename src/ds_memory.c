#include "ds_memory.h"

struct ds_file_struct ds_file;
struct ds_counts_struct ds_counts;

int ds_create(char *filename, long size) {
    int i;

    struct ds_file_struct myFile;
    myFile.fp = fopen(filename, "wb+");
    if (myFile.fp == NULL) { return -1;}

    myFile.block[0].start = 0; //This accessing might be wrong
    myFile.block[0].length = size;
    myFile.block[0].alloced = 0;

    for(i=0; i< MAX_BLOCKS; i++) { 
        myFile.block[i].start = 0;
        myFile.block[i].length = 0;
        myFile.block[i].alloced = 0;
    }

    fclose(myFile.fp);
    return 0;
}