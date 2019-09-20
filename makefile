CFLAGS = -ansi -pedantic -Wall
CC = gcc

all: ds_memory.o ds_array.o
	$(CC) $(CFLAGS) ds_array.o ds_memory.o -o arrayProgram

ds_memory.o: ds_memory.c ds_memory.h
	$(CC) $(CFLAGS) ds_memory.c -c -o ds_memory.o

ds_array.o: ds_array.c ds_array.h
	$(CC) $(CFLAGS) ds_array.c -c -o ds_array.o

clean:
	rm ds_memory
	rm ds_array