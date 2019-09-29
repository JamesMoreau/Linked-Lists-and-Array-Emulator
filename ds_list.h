/*guards*/
#ifndef __LISTH__
#define __LISTH__

/*Libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Globals*/


/*Structures*/
struct ds_list_item_struct {
    int item;
    long next;
};

/*Functions*/
int ds_create_list();
int ds_init_list();
int ds_insert(int, long);
int ds_finish_list();
int ds_delete(long);
int ds_replace(int, long);
void show_list();


#endif
