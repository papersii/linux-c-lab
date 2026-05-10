CC = gcc
CFLAGS = -g -Wall

all: hello

hello: hello.c
	$(CC) $(CFLAGS) hello.c -o hello

clean:
	rm -f hello
