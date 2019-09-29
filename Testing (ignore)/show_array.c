#include "ds_memory.h"
#include "ds_array.h"

int main() {
    ds_init_array();
    printf("here1");
    ds_finish_array();
    printf("here2");
    show_array();
}