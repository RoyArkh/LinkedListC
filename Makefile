CC = gcc
CFLAGS = -Wall -g

all: clean install
	./program

clean: 
	rm -f *.o program

main.o:
	$(CC) $(CFLAGS) -c main.c

linkedlist.o:
	$(CC) $(CFLAGS) -c linkedlist.c

program: linkedlist.o main.o
	$(CC) $(CFLAGS) -o program main.c linkedlist.c

install: program
