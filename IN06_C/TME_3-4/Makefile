CFLAGS = -g -Wall -Wextra -pedantic -Wno-unused-parameter
CC = gcc

PROGRAMS = mainLC mainH

.PHONY:	all clean

all: $(PROGRAMS)

mainLC: biblioLC.o entreeSortieLC.o mainLC.o
	$(CC) -o $@ $(CFLAGS) $^

mainH: biblioH.o entreeSortieH.o mainH.o
	$(CC) -o $@ $(CFLAGS) $^
	
biblioLC.o: biblioLC.c
	gcc $(CFLAGS) -c biblioLC.c

entreeSortieLC.o: entreeSortieLC.c
	gcc $(CFLAGS) -c entreeSortieLC.c

biblioH.o: biblioH.c
	gcc $(CFLAGS) -c biblioH.c

entreeSortieH.o: entreeSortieH.c
	gcc $(CFLAGS) -c entreeSortieH.c

mainLC.o: mainLC.c
	gcc $(CFLAGS) -c mainLC.c

clean:
	rm -f *.o *~ $(PROGRAMS)

