/*
NAME:   James Moreau
STUDENT ID: 1065510
EMAIL:  jmorea03@uoguelph.ca*/
/*guards*/
#ifndef __LISTH__
#define __LISTH__

/*Libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
int ds_read_elements(char*);
int ds_delete(long);
int ds_replace(int, long);
int ds_swap(long, long);
long ds_find(int);
void show_list();


#endif
