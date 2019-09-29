#include "ds_list.h"
#include "ds_memory.h"

int main() {

    ds_create("list.bin", 2048);

    ds_create_list();

    ds_init_list(); /*Remember this sets r/w s to 0;*/


    ds_insert(32, 0);
    ds_insert(21, 1);
    ds_insert(5, 2);
    ds_insert(13, 3);
    ds_insert(20, 4);
    ds_insert(41, 5);
    ds_insert(-23, 6);

    ds_swap(1, 4);
    ds_swap(4, 1);
    show_list();
    ds_finish_list();

   return 0;
}