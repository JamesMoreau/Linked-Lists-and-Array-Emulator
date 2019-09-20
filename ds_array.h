/*guards*/
#ifndef __ARRAYH__
#define __ARRAYH__

/*Globals*/
#define MAX_ELEMENTS 256

/*Libraries*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Functions*/
int ds_create_array();
int ds_init_array();
int ds_replace(int, long);
int ds_insert(int, long);
int ds_delete (long);
#endif