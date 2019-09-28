#include "ds_list.h"
#include "ds_memory.h"

void ds_create_list() {
    ds_init("list.bin");
    long pos;
    long temp;
    pos = 0;
    temp = -1;

    if(ds_malloc(sizeof(long)) == -1) {return 1;}
    if(ds_write(pos, &temp, sizeof(long))) { return 1;}
    ds_finish();
    return 0;
}

int ds_init_list() {
    if(ds_init("list.bin")) {return 1;}
    return 0;
}

ds_insert(int value, long index) {
    int i;
    long pos;
    long last_item_loc;
    struct ds_list_item_struct previous, new;
    
    pos = 0;
    last_item_loc = 0;
    ds_read(&previous.next, pos, sizeof(previous.next));

    for (i = index; i>0; i--) {
        if (previous.next == -1) { return -1;}
        last_item_loc = previous.next;
        ds_read(&previous, previous.next, sizeof(struct ds_list_item_struct));     
    }

    new.item = value;
    new.next = previous.next;
    previous.next = ds_malloc(sizeof(struct ds_list_item_struct));
    if (previous.next == -1) { return 1;}

    if(ds_write(previous.next, &new, sizeof(struct ds_list_item_struct))) {return 1;}

    if(last_item_loc ==  0) { 
        return 0;
    } else {
        ds_write(last_item_loc, &previous, sizeof(struct ds_list_item_struct));
    }
    
    return 0;
}