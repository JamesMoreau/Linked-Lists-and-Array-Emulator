#include "ds_memory.h"
#include "ds_array.h"

int main()

{

    unsigned char c1;

    unsigned short s1;

    unsigned int i1;

    unsigned long l1;

    float f1;

    double d1;

    long memory[6] = {0, 2, 6, 14, 10, 30};

    /* values copied from output of ds_write */
    printf("here\n");

    ds_create("ds_create", 1024);

    printf("here1\n");
    ds_read(&c1, memory[0], sizeof(c1));
    printf("here2\n");

    ds_read(&s1, memory[1], sizeof(s1));

    ds_read(&i1, memory[2], sizeof(i1));

    ds_read(&l1, memory[3], sizeof(l1));

    ds_read(&f1, memory[4], sizeof(f1));

    ds_read(&d1, memory[5], sizeof(d1));

    printf("%d\n%d\n%d\n%ld\n%f\n%f\n", c1, s1, i1, l1, f1, d1);

    ds_finish();

    return 0;
}
