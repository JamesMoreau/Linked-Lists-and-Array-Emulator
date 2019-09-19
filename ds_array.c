#include "ds_array.h"
#include "ds_memory.h"

long elements;

int ds_create_array() {
    char * myFile = "array.bin"; //Might not be called this
    ds_init(myFile);

    long myStart = ds_malloc(sizeof(long));
    if (myStart == -1) {return -1;}



    ds_finish();
    return 0;
}

int ds_init_array() {
    
}