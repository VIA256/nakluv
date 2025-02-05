CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c99
LDFLAGS=-lvulkan

vulkussy: main.o
	$(CC) *.o $(LDFLAGS) -o vulkussy

main.o: main.c
	$(CC) -c main.c $(CFLAGS) -o main.o

clean:
	rm -f *.o
