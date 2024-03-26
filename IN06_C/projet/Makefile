CFLAGS = -g -Wall -Wextra -pedantic -Wno-unused-parameter
CC = gcc
LDFLAGS = -lm

PROGRAMS = mainR #mainCH

.PHONY:	all clean

all: $(PROGRAMS)

#mainCH: SVGwriter.o Chaine.o
#	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)

mainR: SVGwriter.o Chaine.o Reseau.o Hachage.o ReconstitueReseau.o
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)
	
SVGwriter.o: SVGwriter.c
	gcc $(CFLAGS) -c SVGwriter.c

Chaine.o: Chaine.c
	gcc $(CFLAGS) -c Chaine.c

Reseau.o: Reseau.c
	gcc $(CFLAGS) -c Reseau.c

Hachage.o: Hachage.c
	gcc $(CFLAGS) -c Hachage.c

ReconstitueReseau.o: ReconstitueReseau.c
	gcc $(CFLAGS) -c ReconstitueReseau.c

clean:
	rm -f *.o *~ $(PROGRAMS)
