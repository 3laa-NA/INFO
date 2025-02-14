#CFLAGS = -g -Wall -Wextra -pedantic -Wno-unused-parameter
CFLAGS = -g -Wno-unused-parameter
CC = gcc

PROGRAMS = maintab

.PHONY:	all clean

all: $(PROGRAMS)

maintab: tab.o maintab.o
	$(CC) -o $@ $(CFLAGS) $^

tab.o: tab.c
	gcc $(CFLAGS) -c tab.c

maintab.o: maintab.c 
	gcc $(CFLAGS) -c maintab.c

#Ou plus simplement
#%.o:%.c %.h
#	$(CC)  $(GCC_FLAGS) -c  $<


clean:
	rm -f *.o *~ $(PROGRAMS)
