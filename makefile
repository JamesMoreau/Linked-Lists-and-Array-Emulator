CFLAGS = -ansi -pedantic -Wall
CC = gcc

all: ds_memory.o ds_array.o main.o
	$(CC) $(CFLAGS) ds_array.o ds_memory.o main.o -o Test

ds_memory.o: ds_memory.c ds_memory.h
	$(CC) $(CFLAGS) ds_memory.c -c -o ds_memory.o

ds_array.o: ds_array.c ds_array.h
	$(CC) $(CFLAGS) ds_array.c -c -o ds_array.o

main.o: main.c
	$(CC) $(CFLAGS) main.c -c -o main.o

cleanW:
	del *.exe
	del *.o

cleanL:
	rm *.exe
	rm *.o