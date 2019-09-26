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
    ds_test_init();

    return 0;
}
