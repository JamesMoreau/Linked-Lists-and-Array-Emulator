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
    ds_insert(1, 3);
    ds_swap(1, 2);

    /*4 5 2 1 */
    printf("2 is at index %ld\n", ds_find(2));
    ds_finish();

    return 0;
}