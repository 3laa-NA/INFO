CFLAGS = -g -Wall -Wextra -pedantic -Wno-unused-parameter
CC = gcc

PROGRAMS = biblioLC entreeSortieLC main_biblio

.PHONY:	all clean

all: $(PROGRAMS)

biblioLC: biblioLC.o
	$(CC) -o $@ $(CFLAGS) $^
	
entreeSortieLC: entreeSortieLC.o
	$(CC) -o $@ $(CFLAGS) $^

main_biblio: entreeSortieLC.o biblioLC.o main.o
	$(CC) -o $@ $(CFLAGS) $^

clean:
	rm -f *.o *~ $(PROGRAMS)

