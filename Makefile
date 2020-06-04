CC=gcc
CFLAGS=-D_FILE_OFFSET_BITS=64 -g -lm -lpthread


all:
	$(CC) $(CFLAGS) ./src/transposeDbl_1thread.c ./src/utilit.c ./src/utilit.h -o run

clean:
	rm ./src/*.gch
