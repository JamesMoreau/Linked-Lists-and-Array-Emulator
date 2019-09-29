#include "ds_list.h"
#include "ds_memory.h"
#include <time.h>

int main() {

    ds_create("list.bin", 2048);

    ds_create_list();

    ds_init_list(); /*Remember this sets r/w s to 0;*/

    ds_insert(10, 0);
    ds_insert(34, 1);
    ds_insert(-12, 2);
    ds_insert(32, 3);
    ds_insert(94, 4);
    ds_insert(2, 5);

    /*Write a for loop here to open each numbersfile*/
    /*printf("Elements reading in from file\n");
    ds_read_elements("numbers100.txt");
    ds_reset();

    printf("List Replace\n");
    ds_replace(0, 92);
    ds_print_counts();
    ds_reset();

    printf("List insert\n");
    ds_insert(0,46);
    ds_print_counts();
    ds_reset();

    printf("list delete\n");
    ds_delete(rand() % 100);
    ds_print_counts();
    ds_reset();

    printf("List swap\n");
    ds_swap(rand() % 100, rand() % 100);
    ds_print_counts();
    ds_reset();

    show_list();*/
    ds_finish_list();

    return 0;
}