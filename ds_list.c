/*
NAME:   James Moreau
STUDENT ID: 1065510
EMAIL:  jmorea03@uoguelph.ca*/
#include "ds_list.h"
#include "ds_memory.h"

int ds_create_list() {
    long pos;
    long temp;
    pos = 0;
    temp = -1;

    ds_init("list.bin");

    if(ds_malloc(sizeof(long)) == -1) {return 1;}
    if(ds_write(pos, &temp, sizeof(long))) { return 1;}
    ds_finish();
    return 0;
}

int ds_init_list() {
    if(ds_init("list.bin")) {return 1;}
    return 0;
}

int ds_insert(int value, long index) {
    int i;
    long StartOfFile;
    long last_item_loc;
    struct ds_list_item_struct previous, new;
    
    StartOfFile = 0;
    last_item_loc = 0;
    ds_read(&previous.next, StartOfFile, sizeof(long));

    for (i = index; i>0; i--) {
        if (previous.next == -1) { return -1;}
        last_item_loc = previous.next;
        ds_read(&previous, previous.next, sizeof(struct ds_list_item_struct));     
    }

    new.item = value;
    new.next = previous.next;
    previous.next = ds_malloc(sizeof(struct ds_list_item_struct));
    if (previous.next == -1) { return 1;}

    ds_write(previous.next, &new, sizeof(struct ds_list_item_struct));

    if(last_item_loc == StartOfFile) {
        ds_write(StartOfFile, &previous.next, sizeof(long));
        return 0;
    }

    ds_write(last_item_loc, &previous, sizeof(struct ds_list_item_struct));

    return 0;
}

int ds_finish_list() {
    if(ds_finish()) {return 1;}
    return 0;
}

int ds_read_elements(char *filename) {
    
    int temp;
    int i;
    FILE* myFp = fopen(filename, "r");
    if (myFp == NULL) {return 1;}

    i = 0;

    for(i = 0; i<100; i++) {
        fscanf(myFp, "%d ", &temp);
        /*printf("read in %d\n", temp);*/
        ds_insert(temp, i);
    }

    return 0;
}

int ds_delete(long index) {
    int i;
    long startOfFile;
    long last_item_loc;
    struct ds_list_item_struct previous, after;
    
    if (index < 0) {return 1;}
    
    startOfFile = 0;
    last_item_loc = 0;
    ds_read(&previous.next, startOfFile, sizeof(long));

    for (i = index; i > 0 ; i--) {
        if (previous.next == -1) { return -1;}
        last_item_loc = previous.next;
        ds_read(&previous, previous.next, sizeof(struct ds_list_item_struct));
    }

    ds_read(&after, previous.next, sizeof(struct ds_list_item_struct));
    previous.next = after.next;

    if (last_item_loc == startOfFile) {
        ds_write(startOfFile, &previous.next, sizeof(long));
        return 0;
    }
 
    ds_write(last_item_loc, &previous, sizeof(struct ds_list_item_struct));
    return 0;
}

int ds_replace(int value, long index) {
    int i;
    long StartOfFile;
    struct ds_list_item_struct previous, new;

    /*printf("replacing at random index %ld\n", index);*/

    if(index < 0) {return 1;}

    StartOfFile = 0;
    ds_read(&previous.next, StartOfFile, sizeof(long));

    for (i = index; i > 0; i--) {
        if(previous.next == -1) {return -1;}
        ds_read(&previous, previous.next, sizeof(struct ds_list_item_struct));
    }

    ds_read(&new, previous.next, sizeof(struct ds_list_item_struct));
    new.item = value;
    ds_write(previous.next, &new, sizeof(struct ds_list_item_struct));

    return 0;
}

int ds_swap(long index1, long index2) {
    int i;
    long startOfFile;
    long loc_one, loc_two;
    int val1, val2;
    struct ds_list_item_struct temp;
    
    if ( (index1 < 0) || (index2 <0) ) {return 1;}

    startOfFile = 0;
    ds_read(&temp.next, startOfFile, sizeof(long)); /*Getting first value*/

    for (i = index1; i > 0; i--) {
        if(temp.next == -1) {return 1;}
        ds_read(&temp, temp.next, sizeof(struct ds_list_item_struct));
    }
    loc_one = temp.next;
    ds_read(&val1, loc_one, sizeof(int));

    ds_read(&temp.next, startOfFile, sizeof(long)); /*getting second value*/

    for (i = index2; i > 0; i--) {
        if(temp.next == -1) {return 1;}
        ds_read(&temp, temp.next, sizeof(struct ds_list_item_struct));
    }
    loc_two = temp.next;
    ds_read(&val2, loc_two, sizeof(int));

    ds_write(loc_one, &val2, sizeof(int));
    ds_write(loc_two, &val1, sizeof(int));

    return 0;
}

long ds_find(int target) {
    int i;
    long startOfFile;
    struct ds_list_item_struct temp;

    startOfFile = 0;
    i = 0;
    ds_read(&temp.next, startOfFile, sizeof(long));

    while (temp.next != -1) {
        ds_read(&temp, temp.next, sizeof(struct ds_list_item_struct));
        if (temp.item == target) { return i;}
        i++;
    }
    return -1;
}

void show_list() {
    long loc;
    long startOfFile;
    struct ds_list_item_struct li;
    /*
    ds_test_init();
    */
    startOfFile = 0;
    ds_read(&loc, startOfFile, sizeof(long));
    if (loc == -1) {return;}
    
    while(li.next != -1) {
        ds_read(&li, loc, sizeof(struct ds_list_item_struct));
        loc = li.next;
        printf("Node value: %d\n", li.item);
        /*printf("next value: %ld\n", li.next);*/
    }
    
}