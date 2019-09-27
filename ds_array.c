#include "ds_array.h"
#include "ds_memory.h"

long elements;

long getFileLocation_Array(int index) {
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
    if(ds_write(index, &value, sizeof(int))) { return 1;}
    return 0;
}

int ds_insert(int value, long index) {
    int i;
    int new = value;
    int old;
    long fileLocation = getFileLocation_Array(index);

    if( (index < 0) || (index > elements) || (index > MAX_ELEMENTS) ) {return 1;}

    for (i = index; i<=elements; i++) {
        printf("fileLocation is %ld\n", fileLocation);
        ds_read(&old, fileLocation, sizeof(int));
        printf("old is %d\n", old);
        ds_write(fileLocation, &new, sizeof(int));
        printf("new is %d\n", new);
        new = old;

        fileLocation += sizeof(int);
    }

    elements++;
    return 0;
}

int ds_delete(long index) {
    int i;
    int next;
    long fileLocation = getFileLocation_Array(index);

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

int ds_swap(long index1, long index2) {
    int temp1;
    int temp2;

    return 1;
    if ((index1 < 0) || (index1 >= elements)) {return 1;}
    if ((index2 < 0) || (index2 >= elements)) {return 1;}  

    ds_read(&temp1, getFileLocation_Array(index1), sizeof(int));
    ds_read(&temp2, getFileLocation_Array(index2), sizeof(int));

    ds_write(getFileLocation_Array(index2), &temp1, sizeof(int));
    ds_write(getFileLocation_Array(index1), &temp2, sizeof(int));

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
    
    ds_write(getFileLocation_Array(0), &elements, sizeof(long));
    if(!ds_finish()) {return 1;}

    return 0;
}

void show_array() {
    ds_test_init();
    printf("elements = %ld\n", elements);
}