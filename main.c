#include "ds_memory.h"
#include "ds_array.h"

int main(int argc, char const *argv[])
{

    
    if(ds_create("test.bin", 1234)) {
        printf("Failure making file\n");
    } else {
        printf("Success making file\n");
    }

    if(ds_init("test.bin")) {
        printf("Failure init'ing\n");
    } else {
        printf("Success init'ing\n");
    }

    printf("Calling ds_malloc(10)\n");
    printf("return value is %ld\n", ds_malloc(10));

    printf("calling ds_malloc(100 000)\n");
    printf("return value is %ld\n", ds_malloc(100000));

    ds_test_init();

    return 0;
}
