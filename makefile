CFLAGS = -ansi -pedantic -Wall
CC = gcc

array_test: ds_memory.o ds_array.o array_test.o
	$(CC) $(CFLAGS) ds_memory.o ds_array.o array_test.o -o array_test

list_test: ds_memory.o ds_list.o list_test.o
	$(CC) $(CFLAGS) ds_memory.o ds_list.o list_test.o -o list_test

show_array: ds_memory.o ds_array.o show_array.o
	$(CC) $(CFLAGS) ds_memory.o ds_array.o show_array.o -o show_array

main: ds_memory.o ds_array.o main.o
	$(CC) $(CFLAGS) ds_array.o ds_memory.o main.o -o a1

ds_memory.o: ds_memory.c ds_memory.h
	$(CC) $(CFLAGS) ds_memory.c -c -o ds_memory.o

ds_array.o: ds_array.c ds_array.h
	$(CC) $(CFLAGS) ds_array.c -c -o ds_array.o

array_test.o: array_test.c
	$(CC) $(CFLAGS) array_test.c -c -o array_test.o

list_test.o: list_test.c
	$(CC) $(CFLAGS) list_test.c -c -o list_test.o

show_array.o: show_array.c
	$(CC) $(CFLAGS) show_array.c -c -o show_array.o

main.o: main.c
	$(CC) $(CFLAGS) main.c -c -o main.o

cleanW:
	del *.exe
	del *.o

cleanL:
	rm a1
	rm *.o
	rm *.bin