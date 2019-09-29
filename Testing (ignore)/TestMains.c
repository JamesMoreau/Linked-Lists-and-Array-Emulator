int main(int argc, char const *argv[])
{
    long temp;

    if (ds_create("test.bin", 1234))
    {
        printf("Failure making file\n");
    }
    else
    {
        printf("Success making file\n");
    }

    if (ds_init("test.bin"))
    {
        printf("Failure init'ing\n");
    }
    else
    {
        printf("Success init'ing\n");
    }

    printf("Calling ds_malloc(10)\n");
    temp = ds_malloc(10);
    printf("return value is %ld\n", temp);
    ds_free(temp);

    printf("calling ds_malloc(100 000)\n");
    printf("return value is %ld\n", ds_malloc(100000));
    ds_test_init();

    return 0;
}

int main()
{

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

    ds_test_init();

    ds_finish();

    return 0;
}

int main()
{

    unsigned char c1, c2;

    unsigned short s1, s2;

    unsigned int i1, i2;

    unsigned long l1, l2;

    float f1, f2;

    double d1, d2;

    long memory[12]; /* array to hold all memory allocations */

    int i;

    c1 = 1;
    c2 = 2;
    s1 = 3;
    s2 = 4;
    i1 = 5;
    i2 = 6;
    l1 = 7;
    l2 = 8;
    f1 = 9.0;
    f2 = 10.0;
    d1 = 11.0;
    d2 = 12.0;

    /* create binary file */
    ds_create("test.bin", 1234);

    /* load block array and reset counts */
    ds_init("test.bin");

    /* allocate and write chars, free one of them */
    memory[0] = ds_malloc(sizeof(c1));

    ds_write(memory[0], &c1, sizeof(c1));

    memory[1] = ds_malloc(sizeof(c2));

    ds_write(memory[1], &c2, sizeof(c2));

    ds_free(memory[1]);

    /* allocate and write shorts, free one of them */
    memory[2] = ds_malloc(sizeof(s1));

    ds_write(memory[2], &s1, sizeof(s1));

    memory[3] = ds_malloc(sizeof(s2));

    ds_write(memory[3], &s2, sizeof(s2));

    ds_free(memory[3]);

    /* allocate and write ints, free one of them */
    memory[4] = ds_malloc(sizeof(i1));

    ds_write(memory[4], &i1, sizeof(i1));

    memory[5] = ds_malloc(sizeof(i2));

    ds_write(memory[5], &i2, sizeof(i2));

    ds_free(memory[5]);

    /* allocate and write longs, free one of them */
    memory[6] = ds_malloc(sizeof(l1));

    ds_write(memory[6], &l1, sizeof(l1));

    memory[7] = ds_malloc(sizeof(l2));

    ds_write(memory[7], &l2, sizeof(l2));

    ds_free(memory[7]);

    /* allocate and write floats, free one of them */
    memory[8] = ds_malloc(sizeof(f1));

    ds_write(memory[8], &f1, sizeof(f1));

    memory[9] = ds_malloc(sizeof(f2));

    ds_write(memory[9], &f2, sizeof(f2));

    ds_free(memory[9]);

    /* allocate and write doubles, free one of them */
    memory[10] = ds_malloc(sizeof(d1));

    ds_write(memory[10], &d1, sizeof(d1));

    memory[11] = ds_malloc(sizeof(d2));

    ds_write(memory[11], &d2, sizeof(d2));

    ds_free(memory[11]);

    printf("Remaining memory allocations:\n");

    for (i = 0; i < 12; i += 2) /* skip every other location because we freed them */

    {
        printf("%ld\n", memory[i]);
    }

    ds_test_init();

    ds_finish();

    return 0;
}

int main(int argc, char **argv)
{

    int value;

    long index;
    int temp;

    if (argc != 3)

    {

        printf("Usage:  %svalue index\n", argv[0]);

        return -1;
    }

    value = atoi(argv[1]);

    index = atol(argv[2]);

    ds_create("array.bin", 4096);

    ds_init_array();

    temp = ds_insert(value, index);
    printf("Temp is %d\n", temp);

    show_array();

    ds_finish_array();

    return 0;
}

int main(int argc, char **argv)
{

    ds_create("array.bin", 200);
    ds_create_array();

    ds_insert(4, 0);
    ds_insert(1, 1);
    ds_insert(3, 2);
    ds_insert(21, 3);
    ds_insert(42, 4);

    return 0;
}

int main()
{

    ds_create("list.bin", 2048);

    ds_create_list();

    ds_init_list(); /*Remember this sets r/w s to 0;*/

    ds_insert(32, 0);
    ds_insert(21, 1);
    ds_insert(5, 2);
    ds_insert(13, 3);
    ds_insert(20, 4);
    ds_insert(41, 5);
    ds_insert(23, 6);

    printf("index: %ld\n", ds_find());

    show_list();
    ds_finish_list();

    return 0;
}