#include "ds_memory.h"
#include "ds_array.h"

int main(int argc, char const *argv[])
{
    if(ds_create("this_directory_does_not_exist/test.bin", 0)) {
        printf("Failure\n");
    } else {
        printf("Success\n");
    }
    return 0;
}
