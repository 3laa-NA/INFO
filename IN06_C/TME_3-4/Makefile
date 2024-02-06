CFLAGS = -g -Wall -Wextra -pedantic -Wno-unused-parameter
CC = gcc

PROGRAMS = biblioLC entreeSortieLC

.PHONY:	all clean

all: $(PROGRAMS)

main_biblio: entreeSortieLC.o biblioLC.o main.o
	$(CC) -o $@ $(CFLAGS) $^

clean:
	rm -f *.o *~ $(PROGRAMS)