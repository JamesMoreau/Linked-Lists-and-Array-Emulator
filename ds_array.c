#include "ds_array.h"
#include "ds_memory.h"

long elements;

long getFileLocation(int index) {
    return (index * sizeof(int)) + sizeof(long);
}

int ds_create_array() {
    long myAddress;
    elements = 0;

    ds_init("array.bin");

    myAddress = ds_malloc(sizeof(long));
    printf("My address is %ld\n", myAddress);
    if(ds_write(myAddress, &elements, sizeof(long))) { return 1;}
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
    if( (index < 0) || (index >= elements) ) {return 1;}
    printf("replacing at index %ld with value %d\n", index, value);
    if(ds_write(getFileLocation(index), &value, sizeof(int))) { return 1;}
    return 0;
}

int ds_insert(int value, long index) {
    int i;
    int new = value;
    int old;
    if( (index < 0) || (index > elements) || (index > MAX_ELEMENTS) || (elements == MAX_ELEMENTS)) {return 1;}

    printf("insertion at index %ld of value %d\n", index, value);
    if(index == elements) {
        ds_write(getFileLocation(index), &value, sizeof(int));
        elements++;
    } else {

        for (i = index; i<=elements; i++) {
            printf("fileLocation is %ld\n", getFileLocation(i));
            ds_read(&old, getFileLocation(i), sizeof(int));
            /*printf("old is %d\n", old);*/
            ds_write(getFileLocation(i), &new, sizeof(int));
            /*printf("new is %d\n", new);*/
            new = old;
            /*printf("new after assignment is %d\n",new);*/
        }
        elements++;
    }
    printf("elements is %ld\n", elements);
    return 0;
}

int ds_delete(long index) {
    int i;
    int next;
    long fileLocation = getFileLocation(index);

    if( (index < 0) || (index >= elements)) {return 1;}

    for (i=index; i<(elements-1); i++) {
        ds_read(&next, fileLocation + sizeof(int), sizeof(int));
        ds_write(fileLocation, &next, sizeof(int));

        fileLocation+=sizeof(int);
    }

    elements--;
    return 0;
}

long ds_find(int target) {
    long i;
    int temp;
    for (i=0; i<elements; i++) {
        ds_read(&temp, i * sizeof(int), sizeof(int));
        if (temp == target) {
            return i;
        }
    }
    return -1;
}

int ds_swap(long index1, long index2) { /*Not working*/
    int temp1;
    int temp2;
    if (index1 == index2) {return 1;}
    if ((index1 < 0) || (index1 >= elements)) {return 1;}
    if ((index2 < 0) || (index2 >= elements)) {return 1;}
    
    if(ds_read(&temp1, getFileLocation(index1), sizeof(int)) == NULL) {return 1;}
    if(ds_read(&temp2, getFileLocation(index2), sizeof(int)) == NULL) {return 1;}

    printf("Swapping values %d of index %ld and %d of index %ld\n", temp1, index1, temp2, index2);

    if(ds_write(getFileLocation(index1), &temp2, sizeof(int))) {return 1;}
    printf("here1");
    if(ds_write(getFileLocation(index2), &temp1, sizeof(int))) {return 1;}
    printf("here2");

    return 0;
}

int ds_read_elements(char *filename) {

    int temp;
    FILE* myFp = fopen(filename, "r");
    if (myFp == NULL) {return 1;}

    while(fscanf(myFp, "%d" , &temp) && (elements<MAX_ELEMENTS)) {
        ds_insert(temp, elements);
        elements++;
    }
    
    return 0;
}

int ds_finish_array() {
    
    ds_write(getFileLocation(0), &elements, sizeof(long));
    if(!ds_finish()) {return 1;}

    return 0;
}

void show_array() {
    int i;
    int tempVal;
    ds_test_init();
    printf("elements = %ld\n", elements);
    
    for (i=0; i<elements; i++) {
        ds_read(&tempVal, getFileLocation(i), sizeof(int));
        printf("array[%d] = %d\n", i, tempVal);
    }
}