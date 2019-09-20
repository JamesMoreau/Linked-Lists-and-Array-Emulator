#include "ds_array.h"
#include "ds_memory.h"

long elements;

int ds_create_array() {
    long myAddress;
    elements = 0;
    ds_init("array.bin");

    myAddress = ds_malloc(sizeof(long));
    if(ds_write(myAddress, 0, sizeof(long))) { return 1;}
    
    if(ds_init_array()) {return 1;}

    ds_malloc(sizeof(struct ds_blocks_struct) * MAX_BLOCKS);

    ds_finish();
    return 0;
}

int ds_init_array() {
    if(ds_init("array.bin")) {return 1;}

    ds_read(&elements, 0, sizeof(long));
    return 0;
}

int ds_replace(int value, long index) {
    if(ds_write(index, &value, sizeof(int))) { return 1;}

    return 0;
}

int ds_insert(int value, long index) {
    int i;
    int new, old;
    long fileLocation = (index * sizeof(int)) + sizeof(elements);
    if(index < 0 || index > elements + 1 || index > MAX_ELEMENTS) {return 1;}

    for (i = index; i<elements; i++) {
        ds_read(&old, fileLocation, sizeof(int));
        ds_write(fileLocation, &new, sizeof(int));
        new = old;

        fileLocation += sizeof(int);
    }
    ds_write(fileLocation, &new, sizeof(int)); /*ie. when index == elements*/

    ++elements;
    return 0;
}

int ds_delete (long index) { /*Continue*/

    return 0;
}