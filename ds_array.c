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

int ds_init_array() { //Todo

    
}

int ds_replace(int value, long index) {

    long fileLocation = sizeof(struct ds_blocks_struct) * index; /*Is this the correct calculation?*/
    if(ds_write(fileLocation, (void*) value, sizeof(value))) { return 1;} /*can i do this?*/

    return 0;
}

int ds_insert(int value, long index) {
    struct ds_blocks_struct tempBlock;
    int i;

    if(index == elements) {


        return 0;
    }

    for (i = index; i < elements; i++) {
        tempBlock =
    }
}