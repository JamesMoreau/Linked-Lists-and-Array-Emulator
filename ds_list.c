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
    printf("wrote %ld at position %ld\n", temp, pos);
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

    printf("here4\n");
    new.item = value;
    new.next = previous.next;
    previous.next = ds_malloc(sizeof(struct ds_list_item_struct));
    if (previous.next == -1) { return 1;}

    ds_write(previous.next, &new, sizeof(struct ds_list_item_struct));

    printf("last_item_loc is %ld\n", last_item_loc);
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

void show_list() {
    long loc;
    long startOfFile;
    struct ds_list_item_struct li;
    
    /*
    ds_test_init();
    */

    startOfFile = 0;
    ds_read(&loc, startOfFile, sizeof(long));
    printf("first loc is %ld\n", loc);
    if (loc == -1) {return;}
    
    while(li.next != -1) {
        ds_read(&li, loc, sizeof(struct ds_list_item_struct));
        loc = li.next;
        printf("Node value: %d\n", li.item);
        /*printf("next value: %ld\n", li.next);*/
    }
    
}