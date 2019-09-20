#include "ds_array.h"
#include "ds_memory.h"

long elements;

int ds_create_array() {
    char * myFile = "array.bin";
    ds_init(myFile);

    long myStart = ds_malloc(sizeof(long));
    if(ds_write(myStart, 0, sizeof(long))) { return 1;}

    int myArray[elements] = ds_malloc(sizeof(int) * elements); /*Warning: "expression must have a constant value"*/

    ds_finish();
    return 0;
}

int ds_init_array() {
    if(ds_init("array.bin")) {return 1;}

    elements = ds_read((void *)elements, 0, sizeof(long)); /*should this be casted?*/
    if (elements == NULL) {return 1;} /*does this need to be checked?*/

    return 0;
}

int ds_replace(int value, long index) {
    if(ds_write(index, (void*) value, sizeof(int))) { return 1;}

    return 0;
}

int ds_insert(int value, long index) { /*what should this do to the last element?*/
    int i;
    int new, old;
    long fileLocation = (index * sizeof(int)) + sizeof(elements);
    if(index < 0 || index > elements + 1 || index > MAX_ELEMENTS) {return 1;}

    for (i = index; i<elements; i++) {
        old = ds_read(old, fileLocation, sizeof(int));
        ds_write(fileLocation, new, sizeof(int));
        new = old;

        fileLocation += sizeof(int);
    }
    ds_write(fileLocation, new, sizeof(int)); /*ie. when index == elements*/

    ++elements;
    return 0;
}

int ds_delete (long index) { /*Continue*/

}