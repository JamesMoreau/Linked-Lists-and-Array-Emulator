#include "ds_memory.h"
#include "ds_array.h"

int main(int argc, char** argv) {

    ds_create("array.bin", 1234);
    
    ds_create_array();


    printf("here\n");
    ds_insert(4, 0);
    ds_insert(1, 1);
    ds_insert(3, 2);
    ds_insert(21, 3);
    ds_insert(42, 4);
    ds_insert(4, 2);
    printf("here\n");

    ds_finish();

    return 0;
}