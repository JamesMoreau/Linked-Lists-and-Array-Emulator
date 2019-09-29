#include "ds_memory.h"
#include "ds_array.h"

int main() {

    ds_create("array.bin", 1234);
    
    ds_create_array();

    ds_init_array();

    printf("Elements reading in from file\n");
    ds_read_elements("numbers100.txt");
    ds_reset();

    printf("List Replace\n");
    ds_replace(0, 23);
    ds_print_counts();
    ds_reset();

    printf("List insert\n");
    ds_insert(0, 90);
    ds_print_counts();
    ds_reset();

    printf("list delete\n");
    ds_delete(95);
    ds_print_counts();
    ds_reset();

    printf("List swap\n");
    ds_swap(rand() % 23, rand() % 56);
    ds_print_counts();
    ds_reset();

    show_array();
    ds_finish();

    return 0;
}