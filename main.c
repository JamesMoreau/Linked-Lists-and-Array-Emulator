#include "ds_memory.h"
#include "ds_array.h"

int main() {

    long memory;

    ds_create("test.bin", 1234);
    ds_init("test.bin");

    printf("Calling ds_malloc( 10 )\n");

    memory = ds_malloc(10);

    printf("Return value is %ld\n", memory);

    printf("Calling ds_malloc( 100000 )\n");

    printf("Return value is %ld\n", ds_malloc(100000));

    printf("Calling ds_malloc( 17 )\n");

    printf("Return value is %ld\n", ds_malloc(17));

    ds_free(memory);

    ds_free(17);

    ds_test_init();

    ds_finish();

    return 0;
}
