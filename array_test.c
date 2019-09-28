#include "ds_memory.h"
#include "ds_array.h"

int main(int argc, char** argv) {

    ds_create("array.bin", 1234);
    
    ds_create_array();

    ds_init_array();


    printf("appending values\n");
    ds_insert(4, 0);
    ds_insert(2, 1);
    ds_insert(5, 2);
    ds_insert(10, 3);
    ds_insert(29, 4);
    ds_insert(32, 5);
    ds_insert(1, 6);
    
    ds_replace(100, 2);
    /*printf("ds_swap return is %d\n", ds_swap(2,4));*/

    show_array();
    ds_finish();

    return 0;
}