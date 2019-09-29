#include "ds_list.h"
#include "ds_memory.h"

int main() {

    ds_create("list.bin", 2048);

    ds_create_list();

    ds_init_list(); /*Remember this sets r/w s to 0;*/

    /*Write a for loop here to open each numbersfile*/

    printf("here\n");
    ds_read_elements("numbers.txt"); /*THIS IS STUCK LOOP*/
    printf("here2\n");
    /*ds_replace(0, 1);*/
    ds_finish_list();

    show_list();

   return 0;
}